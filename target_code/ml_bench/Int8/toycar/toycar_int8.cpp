
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/micro/tflite_bridge/micro_error_reporter.h"
#include "tensorflow/lite/schema/schema_generated.h"

#include "toycar_int8_data/toycar_int8_input_data.h"
#include "toycar_int8_data/toycar_int8_model_data.h"
#include "toycar_int8_data/toycar_int8_model_settings.h"
#include "toycar_int8_data/toycar_int8_output_data_ref.h"

#include "../../perfsim.h"

#ifdef VERILATOR
extern "C" {
#include "uart.h"
}
#endif

extern "C" {
MATCH_BEGIN_DEF
MATCH_END_DEF
}

// ASM: __register_exitproc diverge, try this
extern "C" {
void __register_exitproc(void) {}
}

constexpr size_t tensor_arena_size = 256 * 1024;
alignas(16) uint8_t tensor_arena[tensor_arena_size];

int run_test() {
  // tflite::MicroErrorReporter micro_error_reporter;
  // tflite::ErrorReporter *error_reporter = &micro_error_reporter;

#ifdef VERILATOR
  auto x = 10;
  uart_printf("Testprint %i\n", x);
#endif
  const tflite::Model *model = tflite::GetModel(toycar_int8_model_data);

  static tflite::MicroMutableOpResolver<1> resolver;
  resolver.AddFullyConnected();

  tflite::MicroInterpreter interpreter(model, resolver, tensor_arena,
                                       tensor_arena_size);

  if (interpreter.AllocateTensors() != kTfLiteOk) {
    // TF_LITE_REPORT_ERROR(error_reporter, "ERROR: In AllocateTensors().");
    return -1;
  }

  for (size_t i = 0; i < toycar_int8_data_sample_cnt; i++) {
    memcpy(interpreter.input(0)->data.int8, (int8_t *)toycar_int8_input_data[i],
           toycar_int8_input_data_len[i]);

#ifndef VERILATOR
    printf("Sample %i | Input Data Length %i\n", i,
           toycar_int8_input_data_len[i]);
    for (size_t ix = 0; ix < toycar_int8_input_data_len[i]; ix++) {
      auto interpreter_in = interpreter.input(0)->data.int8[ix];
      auto ref_in = toycar_int8_input_data[i][ix];
      printf("Interp %8i | Ref %8i\n", interpreter_in, ref_in);
    }
#endif

    // start_cycle_count(); //RD cycle is illegal, causes a lock on attempted
    // offload

    if (interpreter.Invoke() != kTfLiteOk) {
      // TF_LITE_REPORT_ERROR(error_reporter, "ERROR: In Invoke().");
      return -1;
    }

    int32_t sum = 0;

    for (size_t j = 0; j < toycar_int8_input_data_len[i]; j++) {
      // sum += pow((int8_t)toycar_int8_input_data[i][j] -
      //                interpreter.output(0)->data.int8[j],

      //          2);
      auto input = (int8_t)toycar_int8_input_data[i][j];
      auto output = interpreter.output(0)->data.int8[j];
      auto diff = input - output;
      // auto diff = (int8_t)toycar_int8_input_data[i][j] -
      //             interpreter.output(0)->data.int8[j];
      sum += (diff * diff);

#ifndef VERILATOR
      printf("\tIndex %i | In %8i | Out %8i | Diff %8i | Sum %10i\n", j, input,
             output, diff, sum);
#endif
    }
    sum /= toycar_int8_input_data_len[i];
    uint32_t diff = abs(sum - toycar_int8_output_data_ref[i]);
#ifndef VERILATOR
    printf("Sum / Len %i | Ref %i | Diff %i\n", sum,
           toycar_int8_output_data_ref[i], diff);
#endif
    // store_result_int(diff);

    if (diff > 1) {
      return -1;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {

#ifndef VERILATOR
#endif
  MATCH_BEGIN;
  int ret = run_test();
  MATCH_END;
  if (ret != 0) {
    EXIT_SIM_FAILURE;
  } else {
    EXIT_SIM_SUCCESS;
  }

  return ret;
}
