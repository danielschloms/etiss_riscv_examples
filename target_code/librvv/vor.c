#include "rvv.h"
#include <riscv_vector.h>
#include <stddef.h>
#include <stdint.h>

void vor_vv_i8m1(int8_t *a, int8_t *b, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vint8m1_t va = __riscv_vle8_v_i8m1(a, avl);
    vint8m1_t vb = __riscv_vle8_v_i8m1(b, avl);
    __riscv_vse8_v_i8m1(result, __riscv_vor_vv_i8m1(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i16m1(int16_t *a, int16_t *b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vint16m1_t va = __riscv_vle16_v_i16m1(a, avl);
    vint16m1_t vb = __riscv_vle16_v_i16m1(b, avl);
    __riscv_vse16_v_i16m1(result, __riscv_vor_vv_i16m1(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i32m1(int32_t *a, int32_t *b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e32m1(vl);
    vint32m1_t va = __riscv_vle32_v_i32m1(a, avl);
    vint32m1_t vb = __riscv_vle32_v_i32m1(b, avl);
    __riscv_vse32_v_i32m1(result, __riscv_vor_vv_i32m1(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i8m2(int8_t *a, int8_t *b, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vint8m2_t va = __riscv_vle8_v_i8m2(a, avl);
    vint8m2_t vb = __riscv_vle8_v_i8m2(b, avl);
    __riscv_vse8_v_i8m2(result, __riscv_vor_vv_i8m2(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i16m2(int16_t *a, int16_t *b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vint16m2_t va = __riscv_vle16_v_i16m2(a, avl);
    vint16m2_t vb = __riscv_vle16_v_i16m2(b, avl);
    __riscv_vse16_v_i16m2(result, __riscv_vor_vv_i16m2(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i32m2(int32_t *a, int32_t *b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e32m2(vl);
    vint32m2_t va = __riscv_vle32_v_i32m2(a, avl);
    vint32m2_t vb = __riscv_vle32_v_i32m2(b, avl);
    __riscv_vse32_v_i32m2(result, __riscv_vor_vv_i32m2(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i8m4(int8_t *a, int8_t *b, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vint8m4_t va = __riscv_vle8_v_i8m4(a, avl);
    vint8m4_t vb = __riscv_vle8_v_i8m4(b, avl);
    __riscv_vse8_v_i8m4(result, __riscv_vor_vv_i8m4(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i16m4(int16_t *a, int16_t *b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vint16m4_t va = __riscv_vle16_v_i16m4(a, avl);
    vint16m4_t vb = __riscv_vle16_v_i16m4(b, avl);
    __riscv_vse16_v_i16m4(result, __riscv_vor_vv_i16m4(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i32m4(int32_t *a, int32_t *b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e32m4(vl);
    vint32m4_t va = __riscv_vle32_v_i32m4(a, avl);
    vint32m4_t vb = __riscv_vle32_v_i32m4(b, avl);
    __riscv_vse32_v_i32m4(result, __riscv_vor_vv_i32m4(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i8m8(int8_t *a, int8_t *b, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m8(vl);
    vint8m8_t va = __riscv_vle8_v_i8m8(a, avl);
    vint8m8_t vb = __riscv_vle8_v_i8m8(b, avl);
    __riscv_vse8_v_i8m8(result, __riscv_vor_vv_i8m8(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i16m8(int16_t *a, int16_t *b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m8(vl);
    vint16m8_t va = __riscv_vle16_v_i16m8(a, avl);
    vint16m8_t vb = __riscv_vle16_v_i16m8(b, avl);
    __riscv_vse16_v_i16m8(result, __riscv_vor_vv_i16m8(va, vb, avl), avl);
  }
  return;
}

void vor_vv_i32m8(int32_t *a, int32_t *b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e32m8(vl);
    vint32m8_t va = __riscv_vle32_v_i32m8(a, avl);
    vint32m8_t vb = __riscv_vle32_v_i32m8(b, avl);
    __riscv_vse32_v_i32m8(result, __riscv_vor_vv_i32m8(va, vb, avl), avl);
  }
  return;
}

void vor_vi_i8m1(int8_t *a, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vint8m1_t va = __riscv_vle8_v_i8m1(a, avl);
    vint8m1_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse8_v_i8m1(result, vr, avl);
  }
  return;
}

void vor_vi_i16m1(int16_t *a, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vint16m1_t va = __riscv_vle16_v_i16m1(a, avl);
    vint16m1_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse16_v_i16m1(result, vr, avl);
  }
  return;
}

void vor_vi_i32m1(int32_t *a, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m1(vl);
    vint32m1_t va = __riscv_vle32_v_i32m1(a, avl);
    vint32m1_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse32_v_i32m1(result, vr, avl);
  }
  return;
}

void vor_vi_i8m2(int8_t *a, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vint8m2_t va = __riscv_vle8_v_i8m2(a, avl);
    vint8m2_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse8_v_i8m2(result, vr, avl);
  }
  return;
}

void vor_vi_i16m2(int16_t *a, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vint16m2_t va = __riscv_vle16_v_i16m2(a, avl);
    vint16m2_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse16_v_i16m2(result, vr, avl);
  }
  return;
}

void vor_vi_i32m2(int32_t *a, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m2(vl);
    vint32m2_t va = __riscv_vle32_v_i32m2(a, avl);
    vint32m2_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse32_v_i32m2(result, vr, avl);
  }
  return;
}

void vor_vi_i8m4(int8_t *a, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vint8m4_t va = __riscv_vle8_v_i8m4(a, avl);
    vint8m4_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse8_v_i8m4(result, vr, avl);
  }
  return;
}

void vor_vi_i16m4(int16_t *a, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vint16m4_t va = __riscv_vle16_v_i16m4(a, avl);
    vint16m4_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse16_v_i16m4(result, vr, avl);
  }
  return;
}

void vor_vi_i32m4(int32_t *a, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m4(vl);
    vint32m4_t va = __riscv_vle32_v_i32m4(a, avl);
    vint32m4_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse32_v_i32m4(result, vr, avl);
  }
  return;
}

void vor_vi_i8m8(int8_t *a, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m8(vl);
    vint8m8_t va = __riscv_vle8_v_i8m8(a, avl);
    vint8m8_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse8_v_i8m8(result, vr, avl);
  }
  return;
}

void vor_vi_i16m8(int16_t *a, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m8(vl);
    vint16m8_t va = __riscv_vle16_v_i16m8(a, avl);
    vint16m8_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse16_v_i16m8(result, vr, avl);
  }
  return;
}

void vor_vi_i32m8(int32_t *a, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m8(vl);
    vint32m8_t va = __riscv_vle32_v_i32m8(a, avl);
    vint32m8_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse32_v_i32m8(result, vr, avl);
  }
  return;
}

void vor_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vint8m1_t va = __riscv_vle8_v_i8m1(a, avl);
    __riscv_vse8_v_i8m1(result, __riscv_vor_vx_i8m1(va, b, avl), avl);
  }
  return;
}

void vor_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vint16m1_t va = __riscv_vle16_v_i16m1(a, avl);
    __riscv_vse16_v_i16m1(result, __riscv_vor_vx_i16m1(va, b, avl), avl);
  }
  return;
}

void vor_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m1(vl);
    vint32m1_t va = __riscv_vle32_v_i32m1(a, avl);
    __riscv_vse32_v_i32m1(result, __riscv_vor_vx_i32m1(va, b, avl), avl);
  }
  return;
}

void vor_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vint8m2_t va = __riscv_vle8_v_i8m2(a, avl);
    __riscv_vse8_v_i8m2(result, __riscv_vor_vx_i8m2(va, b, avl), avl);
  }
  return;
}

void vor_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vint16m2_t va = __riscv_vle16_v_i16m2(a, avl);
    __riscv_vse16_v_i16m2(result, __riscv_vor_vx_i16m2(va, b, avl), avl);
  }
  return;
}

void vor_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m2(vl);
    vint32m2_t va = __riscv_vle32_v_i32m2(a, avl);
    __riscv_vse32_v_i32m2(result, __riscv_vor_vx_i32m2(va, b, avl), avl);
  }
  return;
}

void vor_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vint8m4_t va = __riscv_vle8_v_i8m4(a, avl);
    __riscv_vse8_v_i8m4(result, __riscv_vor_vx_i8m4(va, b, avl), avl);
  }
  return;
}

void vor_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vint16m4_t va = __riscv_vle16_v_i16m4(a, avl);
    __riscv_vse16_v_i16m4(result, __riscv_vor_vx_i16m4(va, b, avl), avl);
  }
  return;
}

void vor_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m4(vl);
    vint32m4_t va = __riscv_vle32_v_i32m4(a, avl);
    __riscv_vse32_v_i32m4(result, __riscv_vor_vx_i32m4(va, b, avl), avl);
  }
  return;
}

void vor_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m8(vl);
    vint8m8_t va = __riscv_vle8_v_i8m8(a, avl);
    __riscv_vse8_v_i8m8(result, __riscv_vor_vx_i8m8(va, b, avl), avl);
  }
  return;
}

void vor_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m8(vl);
    vint16m8_t va = __riscv_vle16_v_i16m8(a, avl);
    __riscv_vse16_v_i16m8(result, __riscv_vor_vx_i16m8(va, b, avl), avl);
  }
  return;
}

void vor_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m8(vl);
    vint32m8_t va = __riscv_vle32_v_i32m8(a, avl);
    __riscv_vse32_v_i32m8(result, __riscv_vor_vx_i32m8(va, b, avl), avl);
  }
  return;
}

void vor_vv_u8m1(uint8_t *a, uint8_t *b, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vuint8m1_t va = __riscv_vle8_v_u8m1(a, avl);
    vuint8m1_t vb = __riscv_vle8_v_u8m1(b, avl);
    __riscv_vse8_v_u8m1(result, __riscv_vor_vv_u8m1(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u16m1(uint16_t *a, uint16_t *b, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vuint16m1_t va = __riscv_vle16_v_u16m1(a, avl);
    vuint16m1_t vb = __riscv_vle16_v_u16m1(b, avl);
    __riscv_vse16_v_u16m1(result, __riscv_vor_vv_u16m1(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u32m1(uint32_t *a, uint32_t *b, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e32m1(vl);
    vuint32m1_t va = __riscv_vle32_v_u32m1(a, avl);
    vuint32m1_t vb = __riscv_vle32_v_u32m1(b, avl);
    __riscv_vse32_v_u32m1(result, __riscv_vor_vv_u32m1(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u8m2(uint8_t *a, uint8_t *b, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vuint8m2_t va = __riscv_vle8_v_u8m2(a, avl);
    vuint8m2_t vb = __riscv_vle8_v_u8m2(b, avl);
    __riscv_vse8_v_u8m2(result, __riscv_vor_vv_u8m2(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u16m2(uint16_t *a, uint16_t *b, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vuint16m2_t va = __riscv_vle16_v_u16m2(a, avl);
    vuint16m2_t vb = __riscv_vle16_v_u16m2(b, avl);
    __riscv_vse16_v_u16m2(result, __riscv_vor_vv_u16m2(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u32m2(uint32_t *a, uint32_t *b, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e32m2(vl);
    vuint32m2_t va = __riscv_vle32_v_u32m2(a, avl);
    vuint32m2_t vb = __riscv_vle32_v_u32m2(b, avl);
    __riscv_vse32_v_u32m2(result, __riscv_vor_vv_u32m2(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u8m4(uint8_t *a, uint8_t *b, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vuint8m4_t va = __riscv_vle8_v_u8m4(a, avl);
    vuint8m4_t vb = __riscv_vle8_v_u8m4(b, avl);
    __riscv_vse8_v_u8m4(result, __riscv_vor_vv_u8m4(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u16m4(uint16_t *a, uint16_t *b, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vuint16m4_t va = __riscv_vle16_v_u16m4(a, avl);
    vuint16m4_t vb = __riscv_vle16_v_u16m4(b, avl);
    __riscv_vse16_v_u16m4(result, __riscv_vor_vv_u16m4(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u32m4(uint32_t *a, uint32_t *b, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e32m4(vl);
    vuint32m4_t va = __riscv_vle32_v_u32m4(a, avl);
    vuint32m4_t vb = __riscv_vle32_v_u32m4(b, avl);
    __riscv_vse32_v_u32m4(result, __riscv_vor_vv_u32m4(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u8m8(uint8_t *a, uint8_t *b, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e8m8(vl);
    vuint8m8_t va = __riscv_vle8_v_u8m8(a, avl);
    vuint8m8_t vb = __riscv_vle8_v_u8m8(b, avl);
    __riscv_vse8_v_u8m8(result, __riscv_vor_vv_u8m8(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u16m8(uint16_t *a, uint16_t *b, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e16m8(vl);
    vuint16m8_t va = __riscv_vle16_v_u16m8(a, avl);
    vuint16m8_t vb = __riscv_vle16_v_u16m8(b, avl);
    __riscv_vse16_v_u16m8(result, __riscv_vor_vv_u16m8(va, vb, avl), avl);
  }
  return;
}

void vor_vv_u32m8(uint32_t *a, uint32_t *b, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, b += avl, result += avl) {
    avl = __riscv_vsetvl_e32m8(vl);
    vuint32m8_t va = __riscv_vle32_v_u32m8(a, avl);
    vuint32m8_t vb = __riscv_vle32_v_u32m8(b, avl);
    __riscv_vse32_v_u32m8(result, __riscv_vor_vv_u32m8(va, vb, avl), avl);
  }
  return;
}

void vor_vi_u8m1(uint8_t *a, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vuint8m1_t va = __riscv_vle8_v_u8m1(a, avl);
    vuint8m1_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse8_v_u8m1(result, vr, avl);
  }
  return;
}

void vor_vi_u16m1(uint16_t *a, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vuint16m1_t va = __riscv_vle16_v_u16m1(a, avl);
    vuint16m1_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse16_v_u16m1(result, vr, avl);
  }
  return;
}

void vor_vi_u32m1(uint32_t *a, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m1(vl);
    vuint32m1_t va = __riscv_vle32_v_u32m1(a, avl);
    vuint32m1_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse32_v_u32m1(result, vr, avl);
  }
  return;
}

void vor_vi_u8m2(uint8_t *a, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vuint8m2_t va = __riscv_vle8_v_u8m2(a, avl);
    vuint8m2_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse8_v_u8m2(result, vr, avl);
  }
  return;
}

void vor_vi_u16m2(uint16_t *a, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vuint16m2_t va = __riscv_vle16_v_u16m2(a, avl);
    vuint16m2_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse16_v_u16m2(result, vr, avl);
  }
  return;
}

void vor_vi_u32m2(uint32_t *a, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m2(vl);
    vuint32m2_t va = __riscv_vle32_v_u32m2(a, avl);
    vuint32m2_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse32_v_u32m2(result, vr, avl);
  }
  return;
}

void vor_vi_u8m4(uint8_t *a, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vuint8m4_t va = __riscv_vle8_v_u8m4(a, avl);
    vuint8m4_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse8_v_u8m4(result, vr, avl);
  }
  return;
}

void vor_vi_u16m4(uint16_t *a, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vuint16m4_t va = __riscv_vle16_v_u16m4(a, avl);
    vuint16m4_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse16_v_u16m4(result, vr, avl);
  }
  return;
}

void vor_vi_u32m4(uint32_t *a, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m4(vl);
    vuint32m4_t va = __riscv_vle32_v_u32m4(a, avl);
    vuint32m4_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse32_v_u32m4(result, vr, avl);
  }
  return;
}

void vor_vi_u8m8(uint8_t *a, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m8(vl);
    vuint8m8_t va = __riscv_vle8_v_u8m8(a, avl);
    vuint8m8_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse8_v_u8m8(result, vr, avl);
  }
  return;
}

void vor_vi_u16m8(uint16_t *a, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m8(vl);
    vuint16m8_t va = __riscv_vle16_v_u16m8(a, avl);
    vuint16m8_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse16_v_u16m8(result, vr, avl);
  }
  return;
}

void vor_vi_u32m8(uint32_t *a, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m8(vl);
    vuint32m8_t va = __riscv_vle32_v_u32m8(a, avl);
    vuint32m8_t vr;
    __asm__ volatile("vor.vi %[vd], %[vs2], %2" : [vd]"=vr"(vr) : [vs2]"vr"(va), "K"(10));
    __riscv_vse32_v_u32m8(result, vr, avl);
  }
  return;
}

void vor_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m1(vl);
    vuint8m1_t va = __riscv_vle8_v_u8m1(a, avl);
    __riscv_vse8_v_u8m1(result, __riscv_vor_vx_u8m1(va, b, avl), avl);
  }
  return;
}

void vor_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m1(vl);
    vuint16m1_t va = __riscv_vle16_v_u16m1(a, avl);
    __riscv_vse16_v_u16m1(result, __riscv_vor_vx_u16m1(va, b, avl), avl);
  }
  return;
}

void vor_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m1(vl);
    vuint32m1_t va = __riscv_vle32_v_u32m1(a, avl);
    __riscv_vse32_v_u32m1(result, __riscv_vor_vx_u32m1(va, b, avl), avl);
  }
  return;
}

void vor_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m2(vl);
    vuint8m2_t va = __riscv_vle8_v_u8m2(a, avl);
    __riscv_vse8_v_u8m2(result, __riscv_vor_vx_u8m2(va, b, avl), avl);
  }
  return;
}

void vor_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m2(vl);
    vuint16m2_t va = __riscv_vle16_v_u16m2(a, avl);
    __riscv_vse16_v_u16m2(result, __riscv_vor_vx_u16m2(va, b, avl), avl);
  }
  return;
}

void vor_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m2(vl);
    vuint32m2_t va = __riscv_vle32_v_u32m2(a, avl);
    __riscv_vse32_v_u32m2(result, __riscv_vor_vx_u32m2(va, b, avl), avl);
  }
  return;
}

void vor_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m4(vl);
    vuint8m4_t va = __riscv_vle8_v_u8m4(a, avl);
    __riscv_vse8_v_u8m4(result, __riscv_vor_vx_u8m4(va, b, avl), avl);
  }
  return;
}

void vor_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m4(vl);
    vuint16m4_t va = __riscv_vle16_v_u16m4(a, avl);
    __riscv_vse16_v_u16m4(result, __riscv_vor_vx_u16m4(va, b, avl), avl);
  }
  return;
}

void vor_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m4(vl);
    vuint32m4_t va = __riscv_vle32_v_u32m4(a, avl);
    __riscv_vse32_v_u32m4(result, __riscv_vor_vx_u32m4(va, b, avl), avl);
  }
  return;
}

void vor_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e8m8(vl);
    vuint8m8_t va = __riscv_vle8_v_u8m8(a, avl);
    __riscv_vse8_v_u8m8(result, __riscv_vor_vx_u8m8(va, b, avl), avl);
  }
  return;
}

void vor_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e16m8(vl);
    vuint16m8_t va = __riscv_vle16_v_u16m8(a, avl);
    __riscv_vse16_v_u16m8(result, __riscv_vor_vx_u16m8(va, b, avl), avl);
  }
  return;
}

void vor_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length) {
  int vl = length;
  for (size_t avl; vl > 0; vl -= avl, a += avl, result += avl) {
    avl = __riscv_vsetvl_e32m8(vl);
    vuint32m8_t va = __riscv_vle32_v_u32m8(a, avl);
    __riscv_vse32_v_u32m8(result, __riscv_vor_vx_u32m8(va, b, avl), avl);
  }
  return;
}

