#include "rvv.h"
#include <riscv_vector.h>
#include <stddef.h>
#include <stdint.h>

void vwsub_vv_i16m2(int8_t *a, int8_t *b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vint8m1_t va = __riscv_vle8_v_i8m1(a, avl);
    vint8m1_t vb = __riscv_vle8_v_i8m1(b, avl);
    __riscv_vse16_v_i16m2(result, __riscv_vwsub_vv_i16m2(va, vb, avl), avl);
  }
  return;
}

void vwsub_vv_i32m2(int16_t *a, int16_t *b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vint16m1_t va = __riscv_vle16_v_i16m1(a, avl);
    vint16m1_t vb = __riscv_vle16_v_i16m1(b, avl);
    __riscv_vse32_v_i32m2(result, __riscv_vwsub_vv_i32m2(va, vb, avl), avl);
  }
  return;
}

void vwsub_vv_i16m4(int8_t *a, int8_t *b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vint8m2_t va = __riscv_vle8_v_i8m2(a, avl);
    vint8m2_t vb = __riscv_vle8_v_i8m2(b, avl);
    __riscv_vse16_v_i16m4(result, __riscv_vwsub_vv_i16m4(va, vb, avl), avl);
  }
  return;
}

void vwsub_vv_i32m4(int16_t *a, int16_t *b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vint16m2_t va = __riscv_vle16_v_i16m2(a, avl);
    vint16m2_t vb = __riscv_vle16_v_i16m2(b, avl);
    __riscv_vse32_v_i32m4(result, __riscv_vwsub_vv_i32m4(va, vb, avl), avl);
  }
  return;
}

void vwsub_vv_i16m8(int8_t *a, int8_t *b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vint8m4_t va = __riscv_vle8_v_i8m4(a, avl);
    vint8m4_t vb = __riscv_vle8_v_i8m4(b, avl);
    __riscv_vse16_v_i16m8(result, __riscv_vwsub_vv_i16m8(va, vb, avl), avl);
  }
  return;
}

void vwsub_vv_i32m8(int16_t *a, int16_t *b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vint16m4_t va = __riscv_vle16_v_i16m4(a, avl);
    vint16m4_t vb = __riscv_vle16_v_i16m4(b, avl);
    __riscv_vse32_v_i32m8(result, __riscv_vwsub_vv_i32m8(va, vb, avl), avl);
  }
  return;
}

void vwsub_wv_i16m2(int16_t *a, int8_t *b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vint16m2_t va = __riscv_vle16_v_i16m2(a, avl);
    vint8m1_t vb = __riscv_vle8_v_i8m1(b, avl);
    __riscv_vse16_v_i16m2(result, __riscv_vwsub_wv_i16m2(va, vb, avl), avl);
  }
  return;
}

void vwsub_wv_i32m2(int32_t *a, int16_t *b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vint32m2_t va = __riscv_vle32_v_i32m2(a, avl);
    vint16m1_t vb = __riscv_vle16_v_i16m1(b, avl);
    __riscv_vse32_v_i32m2(result, __riscv_vwsub_wv_i32m2(va, vb, avl), avl);
  }
  return;
}

void vwsub_wv_i16m4(int16_t *a, int8_t *b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vint16m4_t va = __riscv_vle16_v_i16m4(a, avl);
    vint8m2_t vb = __riscv_vle8_v_i8m2(b, avl);
    __riscv_vse16_v_i16m4(result, __riscv_vwsub_wv_i16m4(va, vb, avl), avl);
  }
  return;
}

void vwsub_wv_i32m4(int32_t *a, int16_t *b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vint32m4_t va = __riscv_vle32_v_i32m4(a, avl);
    vint16m2_t vb = __riscv_vle16_v_i16m2(b, avl);
    __riscv_vse32_v_i32m4(result, __riscv_vwsub_wv_i32m4(va, vb, avl), avl);
  }
  return;
}

void vwsub_wv_i16m8(int16_t *a, int8_t *b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vint16m8_t va = __riscv_vle16_v_i16m8(a, avl);
    vint8m4_t vb = __riscv_vle8_v_i8m4(b, avl);
    __riscv_vse16_v_i16m8(result, __riscv_vwsub_wv_i16m8(va, vb, avl), avl);
  }
  return;
}

void vwsub_wv_i32m8(int32_t *a, int16_t *b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vint32m8_t va = __riscv_vle32_v_i32m8(a, avl);
    vint16m4_t vb = __riscv_vle16_v_i16m4(b, avl);
    __riscv_vse32_v_i32m8(result, __riscv_vwsub_wv_i32m8(va, vb, avl), avl);
  }
  return;
}

void vwsub_vx_i16m2(int8_t *a, int8_t b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vint8m1_t va = __riscv_vle8_v_i8m1(a, avl);
    __riscv_vse16_v_i16m2(result, __riscv_vwsub_vx_i16m2(va, b, avl), avl);
  }
  return;
}

void vwsub_vx_i32m2(int16_t *a, int16_t b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vint16m1_t va = __riscv_vle16_v_i16m1(a, avl);
    __riscv_vse32_v_i32m2(result, __riscv_vwsub_vx_i32m2(va, b, avl), avl);
  }
  return;
}

void vwsub_vx_i16m4(int8_t *a, int8_t b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vint8m2_t va = __riscv_vle8_v_i8m2(a, avl);
    __riscv_vse16_v_i16m4(result, __riscv_vwsub_vx_i16m4(va, b, avl), avl);
  }
  return;
}

void vwsub_vx_i32m4(int16_t *a, int16_t b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vint16m2_t va = __riscv_vle16_v_i16m2(a, avl);
    __riscv_vse32_v_i32m4(result, __riscv_vwsub_vx_i32m4(va, b, avl), avl);
  }
  return;
}

void vwsub_vx_i16m8(int8_t *a, int8_t b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vint8m4_t va = __riscv_vle8_v_i8m4(a, avl);
    __riscv_vse16_v_i16m8(result, __riscv_vwsub_vx_i16m8(va, b, avl), avl);
  }
  return;
}

void vwsub_vx_i32m8(int16_t *a, int16_t b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vint16m4_t va = __riscv_vle16_v_i16m4(a, avl);
    __riscv_vse32_v_i32m8(result, __riscv_vwsub_vx_i32m8(va, b, avl), avl);
  }
  return;
}

void vwsub_wx_i16m2(int16_t *a, int8_t b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vint16m2_t va = __riscv_vle16_v_i16m2(a, avl);
    __riscv_vse16_v_i16m2(result, __riscv_vwsub_wx_i16m2(va, b, avl), avl);
  }
  return;
}

void vwsub_wx_i32m2(int32_t *a, int16_t b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vint32m2_t va = __riscv_vle32_v_i32m2(a, avl);
    __riscv_vse32_v_i32m2(result, __riscv_vwsub_wx_i32m2(va, b, avl), avl);
  }
  return;
}

void vwsub_wx_i16m4(int16_t *a, int8_t b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vint16m4_t va = __riscv_vle16_v_i16m4(a, avl);
    __riscv_vse16_v_i16m4(result, __riscv_vwsub_wx_i16m4(va, b, avl), avl);
  }
  return;
}

void vwsub_wx_i32m4(int32_t *a, int16_t b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vint32m4_t va = __riscv_vle32_v_i32m4(a, avl);
    __riscv_vse32_v_i32m4(result, __riscv_vwsub_wx_i32m4(va, b, avl), avl);
  }
  return;
}

void vwsub_wx_i16m8(int16_t *a, int8_t b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vint16m8_t va = __riscv_vle16_v_i16m8(a, avl);
    __riscv_vse16_v_i16m8(result, __riscv_vwsub_wx_i16m8(va, b, avl), avl);
  }
  return;
}

void vwsub_wx_i32m8(int32_t *a, int16_t b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vint32m8_t va = __riscv_vle32_v_i32m8(a, avl);
    __riscv_vse32_v_i32m8(result, __riscv_vwsub_wx_i32m8(va, b, avl), avl);
  }
  return;
}

