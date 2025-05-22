#include "stddef.h"
#ifdef VERILATOR
#include "terminate.h"
#endif
#include <riscv_vector.h>

#define N_ELEMENTS 256
#define N_ROUNDS 100

int main() {

  for (int round = 0; round < N_ROUNDS; round++) {

    int vl = N_ELEMENTS;

    int32_t a[vl];
    int32_t b[vl];
    int32_t result[vl];
    int32_t result_golden[vl];

    int32_t *a_ptr = a;
    int32_t *b_ptr = b;
    int32_t *result_ptr = result;

    for (int i = 0; i < vl; i++) {
      a[i] = i + round;
      b[i] = (i + 1) * round;
      result_golden[i] = a[i] + b[i];
    }

    for (size_t avl; vl > 0;
         vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
      avl = __riscv_vsetvl_e32m1(vl);
      vint32m1_t va = __riscv_vle32_v_i32m1(a_ptr, avl);
      vint32m1_t vb = __riscv_vle32_v_i32m1(b_ptr, avl);
      __riscv_vse32_v_i32m1(result_ptr, __riscv_vadd_vv_i32m1(va, vb, avl),
                            avl);
    }

    int fail_cnt = 0;
    for (int i = 0; i < N_ELEMENTS; i++) {
      if (result[i] != result_golden[i]) {
        fail_cnt++;
      }
    }
  }

#ifdef VERILATOR
  terminate_success();
#endif
  return 0;
}