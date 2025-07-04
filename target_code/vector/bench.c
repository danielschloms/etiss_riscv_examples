#include <riscv_vector.h>
#include <stdint.h>

#ifdef VERILATOR
#include "terminate.h"
#else
#include <stdio.h>
#endif

#define N_ELEMENTS 32
#define N_ROUNDS 1

#define ADD 0
#define SUB 1
#define OR 2
#define MUL 3
#define DIV 4

#define INT_OP_END 1

#define FADD 0
#define FSUB 1
#define FMUL 2
#define FDIV 3

#define FLOAT_OP_END 0

// static inline __attribute__((always_inline))

int __attribute__((noinline)) address_match_start() { return 1; }

int __attribute__((noinline)) address_match_end() { return 2; }

// Function declarations

// Vector Arithmetic 32 bit signed elements
void v_int_arith_i32x1(int32_t *a_ptr, int32_t *b_ptr, int32_t *result_ptr,
                       unsigned operation);

void v_int_arith_i32x2(int32_t *a_ptr, int32_t *b_ptr, int32_t *result_ptr,
                       unsigned operation);

void v_int_arith_i32x4(int32_t *a_ptr, int32_t *b_ptr, int32_t *result_ptr,
                       unsigned operation);

void v_int_arith_i32x8(int32_t *a_ptr, int32_t *b_ptr, int32_t *result_ptr,
                       unsigned operation);

// Vector Arithmetic 16 bit signed elements
void v_int_arith_i16x1(int16_t *a_ptr, int16_t *b_ptr, int16_t *result_ptr,
                       unsigned operation);

void v_int_arith_i16x2(int16_t *a_ptr, int16_t *b_ptr, int16_t *result_ptr,
                       unsigned operation);

void v_int_arith_i16x4(int16_t *a_ptr, int16_t *b_ptr, int16_t *result_ptr,
                       unsigned operation);

void v_int_arith_i16x8(int16_t *a_ptr, int16_t *b_ptr, int16_t *result_ptr,
                       unsigned operation);

// Vector Arithmetic 8 bit signed elements
void v_int_arith_i8x1(int8_t *a_ptr, int8_t *b_ptr, int8_t *result_ptr,
                      unsigned operation);

void v_int_arith_i8x2(int8_t *a_ptr, int8_t *b_ptr, int8_t *result_ptr,
                      unsigned operation);

void v_int_arith_i8x4(int8_t *a_ptr, int8_t *b_ptr, int8_t *result_ptr,
                      unsigned operation);

void v_int_arith_i8x8(int8_t *a_ptr, int8_t *b_ptr, int8_t *result_ptr,
                      unsigned operation);

// Function to group by data type

int run_v_int_arith_i32(int op, int round);

int run_v_int_arith_i16(int op, int round);

int run_v_int_arith_i8(int op, int round);

int check_float_result(float *result, float *result_golden) {
  int n_errors = 0;
  for (int i = 0; i < N_ELEMENTS; i++) {
    // printf("Result %f, Reference: %f\n", result[i], result_golden[i]);
    if (result[i] != result_golden[i]) {
      // printf("Float Error: Result %f, Reference: %f\n", result[i],
      // result_golden[i]);
      n_errors++;
    }
  }

  if (n_errors) {
    return -1;
  }
  return 0;
}

int check_int_result_i32(int32_t *result, int32_t *result_golden) {
  int n_errors = 0;
  for (int i = 0; i < N_ELEMENTS; i++) {
    if (result[i] != result_golden[i]) {
      // printf("Int Error: Result %i, Reference: %i}\n", result[i],
      //  result_golden[i]);
      n_errors++;
    }
  }

  if (n_errors) {
    return -1;
  }
  return 0;
}

int check_int_result_i16(int16_t *result, int16_t *result_golden) {
  int n_errors = 0;
  for (int i = 0; i < N_ELEMENTS; i++) {
    if (result[i] != result_golden[i]) {
      // printf("Int Error: Result %i, Reference: %i}\n", result[i],
      //  result_golden[i]);
      n_errors++;
    }
  }

  if (n_errors) {
    return -1;
  }
  return 0;
}

int check_int_result_i8(int8_t *result, int8_t *result_golden) {
  int n_errors = 0;
  for (int i = 0; i < N_ELEMENTS; i++) {
    if (result[i] != result_golden[i]) {
      // printf("Int Error: Result %i, Reference: %i}\n", result[i],
      //  result_golden[i]);
      n_errors++;
    }
  }

  if (n_errors) {
    return -1;
  }
  return 0;
}

void float_golden(float *a, float *b, float *result_golden,
                  unsigned operation) {
  for (int i = 0; i < N_ELEMENTS; i++) {
    switch (operation) {
    case FADD:
      result_golden[i] = a[i] + b[i];
      break;
    case FSUB:
      result_golden[i] = a[i] - b[i];
      break;
    case FMUL:
      result_golden[i] = a[i] * b[i];
      break;
    case FDIV:
      result_golden[i] = a[i] / b[i];
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void int_golden_i32(int32_t *a, int32_t *b, int32_t *result_golden,
                    unsigned operation) {
  for (int i = 0; i < N_ELEMENTS; i++) {
    switch (operation) {
    case ADD:
      result_golden[i] = a[i] + b[i];
      break;
    case SUB:
      result_golden[i] = a[i] - b[i];
      break;
    case OR:
      result_golden[i] = a[i] | b[i];
      break;
    case MUL:
      result_golden[i] = a[i] * b[i];
      break;
    case DIV:
      result_golden[i] = a[i] / b[i];
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void int_golden_i16(int16_t *a, int16_t *b, int16_t *result_golden,
                    unsigned operation) {
  for (int i = 0; i < N_ELEMENTS; i++) {
    switch (operation) {
    case ADD:
      result_golden[i] = a[i] + b[i];
      break;
    case SUB:
      result_golden[i] = a[i] - b[i];
      break;
    case OR:
      result_golden[i] = a[i] | b[i];
      break;
    case MUL:
      result_golden[i] = a[i] * b[i];
      break;
    case DIV:
      result_golden[i] = a[i] / b[i];
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void int_golden_i8(int8_t *a, int8_t *b, int8_t *result_golden,
                   unsigned operation) {
  for (int i = 0; i < N_ELEMENTS; i++) {
    switch (operation) {
    case ADD:
      result_golden[i] = a[i] + b[i];
      break;
    case SUB:
      result_golden[i] = a[i] - b[i];
      break;
    case OR:
      result_golden[i] = a[i] | b[i];
      break;
    case MUL:
      result_golden[i] = a[i] * b[i];
      break;
    case DIV:
      result_golden[i] = a[i] / b[i];
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

// Vector Integer Arithmetic I32
void v_int_arith_i32x1(int32_t *a_ptr, int32_t *b_ptr, int32_t *result_ptr,
                       unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e32m1(vl);
    vint32m1_t va = __riscv_vle32_v_i32m1(a_ptr, avl);
    vint32m1_t vb = __riscv_vle32_v_i32m1(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse32_v_i32m1(result_ptr, __riscv_vadd_vv_i32m1(va, vb, avl),
                            avl);
      break;
    case SUB:
      __riscv_vse32_v_i32m1(result_ptr, __riscv_vsub_vv_i32m1(va, vb, avl),
                            avl);
      break;
    case OR:
      __riscv_vse32_v_i32m1(result_ptr, __riscv_vor_vv_i32m1(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse32_v_i32m1(result_ptr, __riscv_vmul_vv_i32m1(va, vb, avl),
                            avl);
      break;
    case DIV:
      __riscv_vse32_v_i32m1(result_ptr, __riscv_vdiv_vv_i32m1(va, vb, avl),
                            avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void v_int_arith_i32x2(int32_t *a_ptr, int32_t *b_ptr, int32_t *result_ptr,
                       unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e32m2(vl);
    vint32m2_t va = __riscv_vle32_v_i32m2(a_ptr, avl);
    vint32m2_t vb = __riscv_vle32_v_i32m2(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse32_v_i32m2(result_ptr, __riscv_vadd_vv_i32m2(va, vb, avl),
                            avl);
      break;
    case SUB:
      __riscv_vse32_v_i32m2(result_ptr, __riscv_vsub_vv_i32m2(va, vb, avl),
                            avl);
      break;
    case OR:
      __riscv_vse32_v_i32m2(result_ptr, __riscv_vor_vv_i32m2(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse32_v_i32m2(result_ptr, __riscv_vmul_vv_i32m2(va, vb, avl),
                            avl);
      break;
    case DIV:
      __riscv_vse32_v_i32m2(result_ptr, __riscv_vdiv_vv_i32m2(va, vb, avl),
                            avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void v_int_arith_i32x4(int32_t *a_ptr, int32_t *b_ptr, int32_t *result_ptr,
                       unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e32m4(vl);
    vint32m4_t va = __riscv_vle32_v_i32m4(a_ptr, avl);
    vint32m4_t vb = __riscv_vle32_v_i32m4(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse32_v_i32m4(result_ptr, __riscv_vadd_vv_i32m4(va, vb, avl),
                            avl);
      break;
    case SUB:
      __riscv_vse32_v_i32m4(result_ptr, __riscv_vsub_vv_i32m4(va, vb, avl),
                            avl);
      break;
    case OR:
      __riscv_vse32_v_i32m4(result_ptr, __riscv_vor_vv_i32m4(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse32_v_i32m4(result_ptr, __riscv_vmul_vv_i32m4(va, vb, avl),
                            avl);
      break;
    case DIV:
      __riscv_vse32_v_i32m4(result_ptr, __riscv_vdiv_vv_i32m4(va, vb, avl),
                            avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void v_int_arith_i32x8(int32_t *a_ptr, int32_t *b_ptr, int32_t *result_ptr,
                       unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e32m8(vl);
    vint32m8_t va = __riscv_vle32_v_i32m8(a_ptr, avl);
    vint32m8_t vb = __riscv_vle32_v_i32m8(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse32_v_i32m8(result_ptr, __riscv_vadd_vv_i32m8(va, vb, avl),
                            avl);
      break;
    case SUB:
      __riscv_vse32_v_i32m8(result_ptr, __riscv_vsub_vv_i32m8(va, vb, avl),
                            avl);
      break;
    case OR:
      __riscv_vse32_v_i32m8(result_ptr, __riscv_vor_vv_i32m8(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse32_v_i32m8(result_ptr, __riscv_vmul_vv_i32m8(va, vb, avl),
                            avl);
      break;
    case DIV:
      __riscv_vse32_v_i32m8(result_ptr, __riscv_vdiv_vv_i32m8(va, vb, avl),
                            avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

// Vector Integer Arithmetic I16
void v_int_arith_i16x1(int16_t *a_ptr, int16_t *b_ptr, int16_t *result_ptr,
                       unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vint16m1_t va = __riscv_vle16_v_i16m1(a_ptr, avl);
    vint16m1_t vb = __riscv_vle16_v_i16m1(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse16_v_i16m1(result_ptr, __riscv_vadd_vv_i16m1(va, vb, avl),
                            avl);
      break;
    case SUB:
      __riscv_vse16_v_i16m1(result_ptr, __riscv_vsub_vv_i16m1(va, vb, avl),
                            avl);
      break;
    case OR:
      __riscv_vse16_v_i16m1(result_ptr, __riscv_vor_vv_i16m1(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse16_v_i16m1(result_ptr, __riscv_vmul_vv_i16m1(va, vb, avl),
                            avl);
      break;
    case DIV:
      __riscv_vse16_v_i16m1(result_ptr, __riscv_vdiv_vv_i16m1(va, vb, avl),
                            avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void v_int_arith_i16x2(int16_t *a_ptr, int16_t *b_ptr, int16_t *result_ptr,
                       unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vint16m2_t va = __riscv_vle16_v_i16m2(a_ptr, avl);
    vint16m2_t vb = __riscv_vle16_v_i16m2(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse16_v_i16m2(result_ptr, __riscv_vadd_vv_i16m2(va, vb, avl),
                            avl);
      break;
    case SUB:
      __riscv_vse16_v_i16m2(result_ptr, __riscv_vsub_vv_i16m2(va, vb, avl),
                            avl);
      break;
    case OR:
      __riscv_vse16_v_i16m2(result_ptr, __riscv_vor_vv_i16m2(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse16_v_i16m2(result_ptr, __riscv_vmul_vv_i16m2(va, vb, avl),
                            avl);
      break;
    case DIV:
      __riscv_vse16_v_i16m2(result_ptr, __riscv_vdiv_vv_i16m2(va, vb, avl),
                            avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void v_int_arith_i16x4(int16_t *a_ptr, int16_t *b_ptr, int16_t *result_ptr,
                       unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vint16m4_t va = __riscv_vle16_v_i16m4(a_ptr, avl);
    vint16m4_t vb = __riscv_vle16_v_i16m4(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse16_v_i16m4(result_ptr, __riscv_vadd_vv_i16m4(va, vb, avl),
                            avl);
      break;
    case SUB:
      __riscv_vse16_v_i16m4(result_ptr, __riscv_vsub_vv_i16m4(va, vb, avl),
                            avl);
      break;
    case OR:
      __riscv_vse16_v_i16m4(result_ptr, __riscv_vor_vv_i16m4(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse16_v_i16m4(result_ptr, __riscv_vmul_vv_i16m4(va, vb, avl),
                            avl);
      break;
    case DIV:
      __riscv_vse16_v_i16m4(result_ptr, __riscv_vdiv_vv_i16m4(va, vb, avl),
                            avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void v_int_arith_i16x8(int16_t *a_ptr, int16_t *b_ptr, int16_t *result_ptr,
                       unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e16m8(vl);
    vint16m8_t va = __riscv_vle16_v_i16m8(a_ptr, avl);
    vint16m8_t vb = __riscv_vle16_v_i16m8(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse16_v_i16m8(result_ptr, __riscv_vadd_vv_i16m8(va, vb, avl),
                            avl);
      break;
    case SUB:
      __riscv_vse16_v_i16m8(result_ptr, __riscv_vsub_vv_i16m8(va, vb, avl),
                            avl);
      break;
    case OR:
      __riscv_vse16_v_i16m8(result_ptr, __riscv_vor_vv_i16m8(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse16_v_i16m8(result_ptr, __riscv_vmul_vv_i16m8(va, vb, avl),
                            avl);
      break;
    case DIV:
      __riscv_vse16_v_i16m8(result_ptr, __riscv_vdiv_vv_i16m8(va, vb, avl),
                            avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

// Vector Integer Arithmetic I8
void v_int_arith_i8x1(int8_t *a_ptr, int8_t *b_ptr, int8_t *result_ptr,
                      unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vint8m1_t va = __riscv_vle8_v_i8m1(a_ptr, avl);
    vint8m1_t vb = __riscv_vle8_v_i8m1(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse8_v_i8m1(result_ptr, __riscv_vadd_vv_i8m1(va, vb, avl), avl);
      break;
    case SUB:
      __riscv_vse8_v_i8m1(result_ptr, __riscv_vsub_vv_i8m1(va, vb, avl), avl);
      break;
    case OR:
      __riscv_vse8_v_i8m1(result_ptr, __riscv_vor_vv_i8m1(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse8_v_i8m1(result_ptr, __riscv_vmul_vv_i8m1(va, vb, avl), avl);
      break;
    case DIV:
      __riscv_vse8_v_i8m1(result_ptr, __riscv_vdiv_vv_i8m1(va, vb, avl), avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void v_int_arith_i8x2(int8_t *a_ptr, int8_t *b_ptr, int8_t *result_ptr,
                      unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vint8m2_t va = __riscv_vle8_v_i8m2(a_ptr, avl);
    vint8m2_t vb = __riscv_vle8_v_i8m2(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse8_v_i8m2(result_ptr, __riscv_vadd_vv_i8m2(va, vb, avl), avl);
      break;
    case SUB:
      __riscv_vse8_v_i8m2(result_ptr, __riscv_vsub_vv_i8m2(va, vb, avl), avl);
      break;
    case OR:
      __riscv_vse8_v_i8m2(result_ptr, __riscv_vor_vv_i8m2(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse8_v_i8m2(result_ptr, __riscv_vmul_vv_i8m2(va, vb, avl), avl);
      break;
    case DIV:
      __riscv_vse8_v_i8m2(result_ptr, __riscv_vdiv_vv_i8m2(va, vb, avl), avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void v_int_arith_i8x4(int8_t *a_ptr, int8_t *b_ptr, int8_t *result_ptr,
                      unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vint8m4_t va = __riscv_vle8_v_i8m4(a_ptr, avl);
    vint8m4_t vb = __riscv_vle8_v_i8m4(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse8_v_i8m4(result_ptr, __riscv_vadd_vv_i8m4(va, vb, avl), avl);
      break;
    case SUB:
      __riscv_vse8_v_i8m4(result_ptr, __riscv_vsub_vv_i8m4(va, vb, avl), avl);
      break;
    case OR:
      __riscv_vse8_v_i8m4(result_ptr, __riscv_vor_vv_i8m4(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse8_v_i8m4(result_ptr, __riscv_vmul_vv_i8m4(va, vb, avl), avl);
      break;
    case DIV:
      __riscv_vse8_v_i8m4(result_ptr, __riscv_vdiv_vv_i8m4(va, vb, avl), avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void v_int_arith_i8x8(int8_t *a_ptr, int8_t *b_ptr, int8_t *result_ptr,
                      unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e8m8(vl);
    vint8m8_t va = __riscv_vle8_v_i8m8(a_ptr, avl);
    vint8m8_t vb = __riscv_vle8_v_i8m8(b_ptr, avl);
    switch (operation) {
    case ADD:
      __riscv_vse8_v_i8m8(result_ptr, __riscv_vadd_vv_i8m8(va, vb, avl), avl);
      break;
    case SUB:
      __riscv_vse8_v_i8m8(result_ptr, __riscv_vsub_vv_i8m8(va, vb, avl), avl);
      break;
    case OR:
      __riscv_vse8_v_i8m8(result_ptr, __riscv_vor_vv_i8m8(va, vb, avl), avl);
      break;
    case MUL:
      __riscv_vse8_v_i8m8(result_ptr, __riscv_vmul_vv_i8m8(va, vb, avl), avl);
      break;
    case DIV:
      __riscv_vse8_v_i8m8(result_ptr, __riscv_vdiv_vv_i8m8(va, vb, avl), avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

void v_float_arith(float *a_ptr, float *b_ptr, float *result_ptr,
                   unsigned operation) {
  int vl = N_ELEMENTS;
  for (size_t avl; vl > 0;
       vl -= avl, a_ptr += avl, b_ptr += avl, result_ptr += avl) {
    avl = __riscv_vsetvl_e32m1(vl);
    vfloat32m1_t va = __riscv_vle32_v_f32m1(a_ptr, avl);
    vfloat32m1_t vb = __riscv_vle32_v_f32m1(b_ptr, avl);
    switch (operation) {
    case FADD:
      __riscv_vse32_v_f32m1(result_ptr, __riscv_vfadd_vv_f32m1(va, vb, avl),
                            avl);
      break;
    case FSUB:
      __riscv_vse32_v_f32m1(result_ptr, __riscv_vfsub_vv_f32m1(va, vb, avl),
                            avl);
      break;
    case FMUL:
      __riscv_vse32_v_f32m1(result_ptr, __riscv_vfmul_vv_f32m1(va, vb, avl),
                            avl);
      break;
    case FDIV:
      __riscv_vse32_v_f32m1(result_ptr, __riscv_vfdiv_vv_f32m1(va, vb, avl),
                            avl);
      break;
    default:
      // printf("Illegal operation!\n");
      return;
      break;
    }
  }
}

int run_v_int_arith_i32(int op, int round) {
  int vl = N_ELEMENTS;
  int32_t a[N_ELEMENTS];
  int32_t b[N_ELEMENTS];
  int32_t result[N_ELEMENTS];
  int32_t result_golden[N_ELEMENTS];

  int32_t *a_ptr = a;
  int32_t *b_ptr = b;
  int32_t *result_ptr = result;
  int error = 0;

  for (int i = 0; i < N_ELEMENTS; i++) {
    a[i] = i + round;
    b[i] = (i + 1) + (round << 1);
  }

  int_golden_i32(a, b, result_golden, op);

  v_int_arith_i32x1(a_ptr, b_ptr, result_ptr, op);
  int err = check_int_result_i32(result, result_golden);
  if (err) {
    error = -1;
  }

  v_int_arith_i32x2(a_ptr, b_ptr, result_ptr, op);
  err = check_int_result_i32(result, result_golden);
  if (err) {
    error = -1;
  }

  v_int_arith_i32x4(a_ptr, b_ptr, result_ptr, op);
  err = check_int_result_i32(result, result_golden);
  if (err) {
    error = -1;
  }

  v_int_arith_i32x8(a_ptr, b_ptr, result_ptr, op);
  err = check_int_result_i32(result, result_golden);
  if (err) {
    error = -1;
  }

  return error;
}

int run_v_int_arith_i16(int op, int round) {
  int vl = N_ELEMENTS;
  int16_t a[N_ELEMENTS];
  int16_t b[N_ELEMENTS];
  int16_t result[N_ELEMENTS];
  int16_t result_golden[N_ELEMENTS];

  int16_t *a_ptr = a;
  int16_t *b_ptr = b;
  int16_t *result_ptr = result;
  int error = 0;

  for (int i = 0; i < N_ELEMENTS; i++) {
    a[i] = i + round;
    b[i] = (i + 1) + (round << 1);
  }

  int_golden_i16(a, b, result_golden, op);

  v_int_arith_i16x1(a_ptr, b_ptr, result_ptr, op);
  int err = check_int_result_i16(result, result_golden);
  if (err) {
    error = -1;
  }

  v_int_arith_i16x2(a_ptr, b_ptr, result_ptr, op);
  err = check_int_result_i16(result, result_golden);
  if (err) {
    error = -1;
  }

  v_int_arith_i16x4(a_ptr, b_ptr, result_ptr, op);
  err = check_int_result_i16(result, result_golden);
  if (err) {
    error = -1;
  }

  v_int_arith_i16x8(a_ptr, b_ptr, result_ptr, op);
  err = check_int_result_i16(result, result_golden);
  if (err) {
    error = -1;
  }

  return error;
}

int run_v_int_arith_i8(int op, int round) {
  int vl = N_ELEMENTS;
  int8_t a[N_ELEMENTS];
  int8_t b[N_ELEMENTS];
  int8_t result[N_ELEMENTS];
  int8_t result_golden[N_ELEMENTS];

  int8_t *a_ptr = a;
  int8_t *b_ptr = b;
  int8_t *result_ptr = result;
  int error = 0;

  for (int i = 0; i < N_ELEMENTS; i++) {
    a[i] = i + round;
    b[i] = (i + 1) + (round << 1);
  }

  int_golden_i8(a, b, result_golden, op);

  v_int_arith_i8x1(a_ptr, b_ptr, result_ptr, op);
  int err = check_int_result_i8(result, result_golden);
  if (err) {
    error = -1;
  }

  v_int_arith_i8x2(a_ptr, b_ptr, result_ptr, op);
  err = check_int_result_i8(result, result_golden);
  if (err) {
    error = -1;
  }

  v_int_arith_i8x4(a_ptr, b_ptr, result_ptr, op);
  err = check_int_result_i8(result, result_golden);
  if (err) {
    error = -1;
  }

  v_int_arith_i8x8(a_ptr, b_ptr, result_ptr, op);
  err = check_int_result_i8(result, result_golden);
  if (err) {
    error = -1;
  }

  return error;
}

int run_vector_int() {
  int error = 0;
  for (int round = 0; round < N_ROUNDS; round++) {
    int vl = N_ELEMENTS;
    int32_t a[N_ELEMENTS];
    int32_t b[N_ELEMENTS];
    int32_t result[N_ELEMENTS];
    int32_t result_golden[N_ELEMENTS];

    int32_t *a_ptr = a;
    int32_t *b_ptr = b;
    int32_t *result_ptr = result;

    for (int op = 0; op < INT_OP_END; op++) {

      int err = run_v_int_arith_i32(op, round);

      err |= run_v_int_arith_i16(op, round);

      err |= run_v_int_arith_i8(op, round);
      // int_golden(a, b, result_golden, op);
      // v_int_arith_i32x1(a_ptr, b_ptr, result_ptr, op);
      // int err = check_int_result(result, result_golden);
      // if (err) {
      //   error = -1;
      // }
      // v_int_arith_i32x2(a_ptr, b_ptr, result_ptr, op);
      // err = check_int_result(result, result_golden);
      // if (err) {
      //   error = -1;
      // }
      // v_int_arith_i32x4(a_ptr, b_ptr, result_ptr, op);
      // err = check_int_result(result, result_golden);
      // if (err) {
      //   error = -1;
      // }
      // v_int_arith_i32x8(a_ptr, b_ptr, result_ptr, op);
      // err = check_int_result(result, result_golden);
      // if (err) {
      //   error = -1;
      // }
      error |= err;
    }
  }

  return error;
}

int run_vector_float() {
  int error = 0;
  for (int round = 0; round < N_ROUNDS; round++) {

    int vl = N_ELEMENTS;
    float a[N_ELEMENTS];
    float b[N_ELEMENTS];
    float result[N_ELEMENTS];
    float result_golden[N_ELEMENTS];

    float *a_ptr = a;
    float *b_ptr = b;
    float *result_ptr = result;

    for (int op = 0; op < FLOAT_OP_END; op++) {
      for (int i = 0; i < N_ELEMENTS; i++) {
        a[i] = i + round;
        b[i] = (i + 1) + (round << 1);
      }

      float_golden(a, b, result_golden, op);
      v_float_arith(a_ptr, b_ptr, result_ptr, op);
      int err = check_float_result(result, result_golden);
      if (err) {
        error = -1;
        // printf("Float Round %i Error, op %i\n", round, op);
      }
    }
  }
  return error;
}

void run_scalar_int() {
  for (int round = 0; round < N_ROUNDS; round++) {
    int const a = 12345 - round;
    int const b = 67890 + round;
    unsigned const a_u = 12345 - round;
    unsigned const b_u = 67890 + round;
    int const shift = 3;

    int c = a + b;
    unsigned c_u = a_u + b_u;
    int d = a - b;
    unsigned d_u = a_u - b_u;
    int e = a * b;
    unsigned e_u = a_u * b_u;
    int f = a / b;
    unsigned f_u = a_u / b_u;
    int g = a & b;
    unsigned g_u = a_u & b_u;
    int h = a | b;
    unsigned h_u = a_u | b_u;
    int i = a ^ b;
    unsigned i_u = a_u ^ b_u;
    int j = a % b;
    unsigned j_u = a_u % b_u;
    int k = a << shift;
    unsigned k_u = a_u << shift;
    int l = a >> shift;
    unsigned l_u = a_u >> shift;
    int m = a > b;
    unsigned m_u = a_u > b;
    int n = a >= b;
    unsigned n_u = a_u >= b;
    int o = a < b;
    unsigned o_u = a_u < b;
    int p = a <= b;
    unsigned p_u = a_u <= b;
    int q = a == b;
    unsigned q_u = a_u == b;
    int r = a != b;
    unsigned r_u = a_u != b;
  }
}

void run_scalar_float() {
  for (int round = 0; round < N_ROUNDS; round++) {
    float const a = 123.45 + ((float)(round + 1) / 3.13);
    float const b = 678.90 - ((float)(round + 1) * 2.85);

    float c = a + b;
    float d = a - b;
    float e = a * b;
    float f = a / b;
    float g = a > b;
    float h = a >= b;
    float i = a < b;
    float j = a <= b;
    float k = a == b;
    float l = a != b;
  }
}

int main() {
  int hello = address_match_start();
  run_scalar_int();
  run_scalar_float();
  int err_int = run_vector_int();
  int err_float = run_vector_float();
  int bye = address_match_end();
  // int err_float = run_vector_float();
#ifdef VERILATOR
  if (err_int != 0) {
    terminate_failure();
  }
  if (err_float != 0) {
    terminate_failure();
  }
  terminate_success();
#else
  printf("Done\n");
  if (err_int != 0) {
    printf("Failed vector int tests\n");
  }
  if (err_float != 0) {
    printf("Failed vector float tests\n");
  }
#endif
  return hello + bye;
}
