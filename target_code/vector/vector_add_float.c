#include <riscv_vector.h>
#include <stdio.h>

#define N_ELEMENTS 128
#define N_ROUNDS 1

void calculate_golden(int vl, int round, float *a, float *b,
                      float *result_golden) {
  for (int i = 0; i < vl; i++) {
    a[i] = ((float)i / 3.21f) + (float)(((float)round) * 1.2);
    b[i] = (float)(i + 1) / 1.22f * (float)(((float)round) * 2.3);
    result_golden[i] = a[i] + b[i];
  }
};

int main() {

  printf("Vector Addition: %i rounds with %i elements\n", N_ROUNDS, N_ELEMENTS);
  printf("Hello Float\n");
  for (int round = 0; round < N_ROUNDS; round++) {

    int vl = N_ELEMENTS;

    float a[vl];
    float b[vl];
    float result[vl];
    float result_golden[vl];

    float *a_ptr = a;
    float *b_ptr = b;
    float *result_ptr = result;

    calculate_golden(vl, round, a, b, result_golden);

    // for (int i = 0; i < vl; i++) {
    //   printf("%i %f\n", round, ((float)i) + (float)(((float)round) / 3.1f));
    //   a[i] = ((float)i / 3.21f) + (float)(((float)round) * 1.2);
    //   b[i] = (float)(i + 1) / 1.22f * (float)(((float)round) * 2.3);
    //   result_golden[i] = a[i] + b[i];
    // }

    for (size_t avl; vl > 0;
         vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
      avl = __riscv_vsetvl_e32m1(vl);
      vfloat32m1_t va = __riscv_vle32_v_f32m1(a_ptr, avl);
      vfloat32m1_t vb = __riscv_vle32_v_f32m1(b_ptr, avl);
      __riscv_vse32_v_f32m1(result_ptr, __riscv_vfadd_vv_f32m1(va, vb, avl),
                            avl);
    }

    int fail_cnt = 0;
    for (int i = 0; i < N_ELEMENTS; i++) {
      // printf("Index %i, Result = %f, Expected = %f\n", i, result[i],
      //        result_golden[i]);
      if (result[i] != result_golden[i]) {
        fail_cnt++;
      }
    }
    if (fail_cnt) {
      printf("%i failed elements\n", fail_cnt);
      return 1;
    }
  }

  printf("Success\n");
  return 0;
}