#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

/* --- vadd --- */
void vadd_vv_i8m1(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vadd_vv_i16m1(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vadd_vv_i32m1(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vadd_vv_i8m2(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vadd_vv_i16m2(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vadd_vv_i32m2(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vadd_vv_i8m4(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vadd_vv_i16m4(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vadd_vv_i32m4(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vadd_vv_i8m8(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vadd_vv_i16m8(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vadd_vv_i32m8(int32_t *a, int32_t *b, int32_t *result, size_t length);


void vadd_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length);
void vadd_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length);
void vadd_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length);

void vadd_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length);
void vadd_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length);
void vadd_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length);

void vadd_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length);
void vadd_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length);
void vadd_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length);

void vadd_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length);
void vadd_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length);
void vadd_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length);


void vadd_vi_i8m1(int8_t *a, int8_t *result, size_t length);
void vadd_vi_i16m1(int16_t *a, int16_t *result, size_t length);
void vadd_vi_i32m1(int32_t *a, int32_t *result, size_t length);

void vadd_vi_i8m2(int8_t *a, int8_t *result, size_t length);
void vadd_vi_i16m2(int16_t *a, int16_t *result, size_t length);
void vadd_vi_i32m2(int32_t *a, int32_t *result, size_t length);

void vadd_vi_i8m4(int8_t *a, int8_t *result, size_t length);
void vadd_vi_i16m4(int16_t *a, int16_t *result, size_t length);
void vadd_vi_i32m4(int32_t *a, int32_t *result, size_t length);

void vadd_vi_i8m8(int8_t *a, int8_t *result, size_t length);
void vadd_vi_i16m8(int16_t *a, int16_t *result, size_t length);
void vadd_vi_i32m8(int32_t *a, int32_t *result, size_t length);


void vadd_vv_u8m1(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vadd_vv_u16m1(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vadd_vv_u32m1(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vadd_vv_u8m2(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vadd_vv_u16m2(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vadd_vv_u32m2(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vadd_vv_u8m4(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vadd_vv_u16m4(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vadd_vv_u32m4(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vadd_vv_u8m8(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vadd_vv_u16m8(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vadd_vv_u32m8(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);


void vadd_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vadd_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vadd_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vadd_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vadd_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vadd_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vadd_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vadd_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vadd_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vadd_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vadd_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vadd_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length);


void vadd_vi_u8m1(uint8_t *a, uint8_t *result, size_t length);
void vadd_vi_u16m1(uint16_t *a, uint16_t *result, size_t length);
void vadd_vi_u32m1(uint32_t *a, uint32_t *result, size_t length);

void vadd_vi_u8m2(uint8_t *a, uint8_t *result, size_t length);
void vadd_vi_u16m2(uint16_t *a, uint16_t *result, size_t length);
void vadd_vi_u32m2(uint32_t *a, uint32_t *result, size_t length);

void vadd_vi_u8m4(uint8_t *a, uint8_t *result, size_t length);
void vadd_vi_u16m4(uint16_t *a, uint16_t *result, size_t length);
void vadd_vi_u32m4(uint32_t *a, uint32_t *result, size_t length);

void vadd_vi_u8m8(uint8_t *a, uint8_t *result, size_t length);
void vadd_vi_u16m8(uint16_t *a, uint16_t *result, size_t length);
void vadd_vi_u32m8(uint32_t *a, uint32_t *result, size_t length);


/* --- vsub --- */
void vsub_vv_i8m1(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vsub_vv_i16m1(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vsub_vv_i32m1(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vsub_vv_i8m2(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vsub_vv_i16m2(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vsub_vv_i32m2(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vsub_vv_i8m4(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vsub_vv_i16m4(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vsub_vv_i32m4(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vsub_vv_i8m8(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vsub_vv_i16m8(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vsub_vv_i32m8(int32_t *a, int32_t *b, int32_t *result, size_t length);


void vsub_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length);
void vsub_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length);
void vsub_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length);

void vsub_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length);
void vsub_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length);
void vsub_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length);

void vsub_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length);
void vsub_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length);
void vsub_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length);

void vsub_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length);
void vsub_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length);
void vsub_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length);


void vsub_vv_u8m1(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vsub_vv_u16m1(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vsub_vv_u32m1(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vsub_vv_u8m2(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vsub_vv_u16m2(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vsub_vv_u32m2(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vsub_vv_u8m4(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vsub_vv_u16m4(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vsub_vv_u32m4(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vsub_vv_u8m8(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vsub_vv_u16m8(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vsub_vv_u32m8(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);


void vsub_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vsub_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vsub_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vsub_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vsub_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vsub_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vsub_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vsub_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vsub_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vsub_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vsub_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vsub_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length);


/* --- vrsub --- */
void vrsub_vi_i8m1(int8_t *a, int8_t *result, size_t length);
void vrsub_vi_i16m1(int16_t *a, int16_t *result, size_t length);
void vrsub_vi_i32m1(int32_t *a, int32_t *result, size_t length);

void vrsub_vi_i8m2(int8_t *a, int8_t *result, size_t length);
void vrsub_vi_i16m2(int16_t *a, int16_t *result, size_t length);
void vrsub_vi_i32m2(int32_t *a, int32_t *result, size_t length);

void vrsub_vi_i8m4(int8_t *a, int8_t *result, size_t length);
void vrsub_vi_i16m4(int16_t *a, int16_t *result, size_t length);
void vrsub_vi_i32m4(int32_t *a, int32_t *result, size_t length);

void vrsub_vi_i8m8(int8_t *a, int8_t *result, size_t length);
void vrsub_vi_i16m8(int16_t *a, int16_t *result, size_t length);
void vrsub_vi_i32m8(int32_t *a, int32_t *result, size_t length);


void vrsub_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length);
void vrsub_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length);
void vrsub_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length);

void vrsub_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length);
void vrsub_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length);
void vrsub_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length);

void vrsub_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length);
void vrsub_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length);
void vrsub_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length);

void vrsub_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length);
void vrsub_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length);
void vrsub_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length);


void vrsub_vi_u8m1(uint8_t *a, uint8_t *result, size_t length);
void vrsub_vi_u16m1(uint16_t *a, uint16_t *result, size_t length);
void vrsub_vi_u32m1(uint32_t *a, uint32_t *result, size_t length);

void vrsub_vi_u8m2(uint8_t *a, uint8_t *result, size_t length);
void vrsub_vi_u16m2(uint16_t *a, uint16_t *result, size_t length);
void vrsub_vi_u32m2(uint32_t *a, uint32_t *result, size_t length);

void vrsub_vi_u8m4(uint8_t *a, uint8_t *result, size_t length);
void vrsub_vi_u16m4(uint16_t *a, uint16_t *result, size_t length);
void vrsub_vi_u32m4(uint32_t *a, uint32_t *result, size_t length);

void vrsub_vi_u8m8(uint8_t *a, uint8_t *result, size_t length);
void vrsub_vi_u16m8(uint16_t *a, uint16_t *result, size_t length);
void vrsub_vi_u32m8(uint32_t *a, uint32_t *result, size_t length);


void vrsub_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vrsub_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vrsub_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vrsub_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vrsub_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vrsub_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vrsub_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vrsub_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vrsub_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vrsub_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vrsub_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vrsub_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length);


/* --- vwadd --- */
void vwadd_vv_i16m2(int8_t *a, int8_t *b, int16_t *result, size_t length);
void vwadd_vv_i32m2(int16_t *a, int16_t *b, int32_t *result, size_t length);

void vwadd_vv_i16m4(int8_t *a, int8_t *b, int16_t *result, size_t length);
void vwadd_vv_i32m4(int16_t *a, int16_t *b, int32_t *result, size_t length);

void vwadd_vv_i16m8(int8_t *a, int8_t *b, int16_t *result, size_t length);
void vwadd_vv_i32m8(int16_t *a, int16_t *b, int32_t *result, size_t length);


void vwadd_wv_i16m2(int16_t *a, int8_t *b, int16_t *result, size_t length);
void vwadd_wv_i32m2(int32_t *a, int16_t *b, int32_t *result, size_t length);

void vwadd_wv_i16m4(int16_t *a, int8_t *b, int16_t *result, size_t length);
void vwadd_wv_i32m4(int32_t *a, int16_t *b, int32_t *result, size_t length);

void vwadd_wv_i16m8(int16_t *a, int8_t *b, int16_t *result, size_t length);
void vwadd_wv_i32m8(int32_t *a, int16_t *b, int32_t *result, size_t length);


void vwadd_vx_i16m2(int8_t *a, int8_t b, int16_t *result, size_t length);
void vwadd_vx_i32m2(int16_t *a, int16_t b, int32_t *result, size_t length);

void vwadd_vx_i16m4(int8_t *a, int8_t b, int16_t *result, size_t length);
void vwadd_vx_i32m4(int16_t *a, int16_t b, int32_t *result, size_t length);

void vwadd_vx_i16m8(int8_t *a, int8_t b, int16_t *result, size_t length);
void vwadd_vx_i32m8(int16_t *a, int16_t b, int32_t *result, size_t length);


void vwadd_wx_i16m2(int16_t *a, int8_t b, int16_t *result, size_t length);
void vwadd_wx_i32m2(int32_t *a, int16_t b, int32_t *result, size_t length);

void vwadd_wx_i16m4(int16_t *a, int8_t b, int16_t *result, size_t length);
void vwadd_wx_i32m4(int32_t *a, int16_t b, int32_t *result, size_t length);

void vwadd_wx_i16m8(int16_t *a, int8_t b, int16_t *result, size_t length);
void vwadd_wx_i32m8(int32_t *a, int16_t b, int32_t *result, size_t length);


/* --- vwsub --- */
void vwsub_vv_i16m2(int8_t *a, int8_t *b, int16_t *result, size_t length);
void vwsub_vv_i32m2(int16_t *a, int16_t *b, int32_t *result, size_t length);

void vwsub_vv_i16m4(int8_t *a, int8_t *b, int16_t *result, size_t length);
void vwsub_vv_i32m4(int16_t *a, int16_t *b, int32_t *result, size_t length);

void vwsub_vv_i16m8(int8_t *a, int8_t *b, int16_t *result, size_t length);
void vwsub_vv_i32m8(int16_t *a, int16_t *b, int32_t *result, size_t length);


void vwsub_wv_i16m2(int16_t *a, int8_t *b, int16_t *result, size_t length);
void vwsub_wv_i32m2(int32_t *a, int16_t *b, int32_t *result, size_t length);

void vwsub_wv_i16m4(int16_t *a, int8_t *b, int16_t *result, size_t length);
void vwsub_wv_i32m4(int32_t *a, int16_t *b, int32_t *result, size_t length);

void vwsub_wv_i16m8(int16_t *a, int8_t *b, int16_t *result, size_t length);
void vwsub_wv_i32m8(int32_t *a, int16_t *b, int32_t *result, size_t length);


void vwsub_vx_i16m2(int8_t *a, int8_t b, int16_t *result, size_t length);
void vwsub_vx_i32m2(int16_t *a, int16_t b, int32_t *result, size_t length);

void vwsub_vx_i16m4(int8_t *a, int8_t b, int16_t *result, size_t length);
void vwsub_vx_i32m4(int16_t *a, int16_t b, int32_t *result, size_t length);

void vwsub_vx_i16m8(int8_t *a, int8_t b, int16_t *result, size_t length);
void vwsub_vx_i32m8(int16_t *a, int16_t b, int32_t *result, size_t length);


void vwsub_wx_i16m2(int16_t *a, int8_t b, int16_t *result, size_t length);
void vwsub_wx_i32m2(int32_t *a, int16_t b, int32_t *result, size_t length);

void vwsub_wx_i16m4(int16_t *a, int8_t b, int16_t *result, size_t length);
void vwsub_wx_i32m4(int32_t *a, int16_t b, int32_t *result, size_t length);

void vwsub_wx_i16m8(int16_t *a, int8_t b, int16_t *result, size_t length);
void vwsub_wx_i32m8(int32_t *a, int16_t b, int32_t *result, size_t length);


/* --- vand --- */
void vand_vv_i8m1(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vand_vv_i16m1(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vand_vv_i32m1(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vand_vv_i8m2(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vand_vv_i16m2(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vand_vv_i32m2(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vand_vv_i8m4(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vand_vv_i16m4(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vand_vv_i32m4(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vand_vv_i8m8(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vand_vv_i16m8(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vand_vv_i32m8(int32_t *a, int32_t *b, int32_t *result, size_t length);


void vand_vi_i8m1(int8_t *a, int8_t *result, size_t length);
void vand_vi_i16m1(int16_t *a, int16_t *result, size_t length);
void vand_vi_i32m1(int32_t *a, int32_t *result, size_t length);

void vand_vi_i8m2(int8_t *a, int8_t *result, size_t length);
void vand_vi_i16m2(int16_t *a, int16_t *result, size_t length);
void vand_vi_i32m2(int32_t *a, int32_t *result, size_t length);

void vand_vi_i8m4(int8_t *a, int8_t *result, size_t length);
void vand_vi_i16m4(int16_t *a, int16_t *result, size_t length);
void vand_vi_i32m4(int32_t *a, int32_t *result, size_t length);

void vand_vi_i8m8(int8_t *a, int8_t *result, size_t length);
void vand_vi_i16m8(int16_t *a, int16_t *result, size_t length);
void vand_vi_i32m8(int32_t *a, int32_t *result, size_t length);


void vand_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length);
void vand_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length);
void vand_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length);

void vand_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length);
void vand_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length);
void vand_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length);

void vand_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length);
void vand_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length);
void vand_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length);

void vand_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length);
void vand_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length);
void vand_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length);


void vand_vv_u8m1(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vand_vv_u16m1(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vand_vv_u32m1(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vand_vv_u8m2(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vand_vv_u16m2(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vand_vv_u32m2(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vand_vv_u8m4(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vand_vv_u16m4(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vand_vv_u32m4(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vand_vv_u8m8(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vand_vv_u16m8(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vand_vv_u32m8(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);


void vand_vi_u8m1(uint8_t *a, uint8_t *result, size_t length);
void vand_vi_u16m1(uint16_t *a, uint16_t *result, size_t length);
void vand_vi_u32m1(uint32_t *a, uint32_t *result, size_t length);

void vand_vi_u8m2(uint8_t *a, uint8_t *result, size_t length);
void vand_vi_u16m2(uint16_t *a, uint16_t *result, size_t length);
void vand_vi_u32m2(uint32_t *a, uint32_t *result, size_t length);

void vand_vi_u8m4(uint8_t *a, uint8_t *result, size_t length);
void vand_vi_u16m4(uint16_t *a, uint16_t *result, size_t length);
void vand_vi_u32m4(uint32_t *a, uint32_t *result, size_t length);

void vand_vi_u8m8(uint8_t *a, uint8_t *result, size_t length);
void vand_vi_u16m8(uint16_t *a, uint16_t *result, size_t length);
void vand_vi_u32m8(uint32_t *a, uint32_t *result, size_t length);


void vand_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vand_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vand_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vand_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vand_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vand_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vand_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vand_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vand_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vand_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vand_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vand_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length);


/* --- vor --- */
void vor_vv_i8m1(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vor_vv_i16m1(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vor_vv_i32m1(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vor_vv_i8m2(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vor_vv_i16m2(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vor_vv_i32m2(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vor_vv_i8m4(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vor_vv_i16m4(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vor_vv_i32m4(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vor_vv_i8m8(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vor_vv_i16m8(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vor_vv_i32m8(int32_t *a, int32_t *b, int32_t *result, size_t length);


void vor_vi_i8m1(int8_t *a, int8_t *result, size_t length);
void vor_vi_i16m1(int16_t *a, int16_t *result, size_t length);
void vor_vi_i32m1(int32_t *a, int32_t *result, size_t length);

void vor_vi_i8m2(int8_t *a, int8_t *result, size_t length);
void vor_vi_i16m2(int16_t *a, int16_t *result, size_t length);
void vor_vi_i32m2(int32_t *a, int32_t *result, size_t length);

void vor_vi_i8m4(int8_t *a, int8_t *result, size_t length);
void vor_vi_i16m4(int16_t *a, int16_t *result, size_t length);
void vor_vi_i32m4(int32_t *a, int32_t *result, size_t length);

void vor_vi_i8m8(int8_t *a, int8_t *result, size_t length);
void vor_vi_i16m8(int16_t *a, int16_t *result, size_t length);
void vor_vi_i32m8(int32_t *a, int32_t *result, size_t length);


void vor_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length);
void vor_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length);
void vor_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length);

void vor_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length);
void vor_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length);
void vor_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length);

void vor_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length);
void vor_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length);
void vor_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length);

void vor_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length);
void vor_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length);
void vor_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length);


void vor_vv_u8m1(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vor_vv_u16m1(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vor_vv_u32m1(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vor_vv_u8m2(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vor_vv_u16m2(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vor_vv_u32m2(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vor_vv_u8m4(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vor_vv_u16m4(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vor_vv_u32m4(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vor_vv_u8m8(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vor_vv_u16m8(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vor_vv_u32m8(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);


void vor_vi_u8m1(uint8_t *a, uint8_t *result, size_t length);
void vor_vi_u16m1(uint16_t *a, uint16_t *result, size_t length);
void vor_vi_u32m1(uint32_t *a, uint32_t *result, size_t length);

void vor_vi_u8m2(uint8_t *a, uint8_t *result, size_t length);
void vor_vi_u16m2(uint16_t *a, uint16_t *result, size_t length);
void vor_vi_u32m2(uint32_t *a, uint32_t *result, size_t length);

void vor_vi_u8m4(uint8_t *a, uint8_t *result, size_t length);
void vor_vi_u16m4(uint16_t *a, uint16_t *result, size_t length);
void vor_vi_u32m4(uint32_t *a, uint32_t *result, size_t length);

void vor_vi_u8m8(uint8_t *a, uint8_t *result, size_t length);
void vor_vi_u16m8(uint16_t *a, uint16_t *result, size_t length);
void vor_vi_u32m8(uint32_t *a, uint32_t *result, size_t length);


void vor_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vor_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vor_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vor_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vor_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vor_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vor_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vor_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vor_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vor_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vor_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vor_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length);


/* --- vxor --- */
void vxor_vv_i8m1(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vxor_vv_i16m1(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vxor_vv_i32m1(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vxor_vv_i8m2(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vxor_vv_i16m2(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vxor_vv_i32m2(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vxor_vv_i8m4(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vxor_vv_i16m4(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vxor_vv_i32m4(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vxor_vv_i8m8(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vxor_vv_i16m8(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vxor_vv_i32m8(int32_t *a, int32_t *b, int32_t *result, size_t length);


void vxor_vi_i8m1(int8_t *a, int8_t *result, size_t length);
void vxor_vi_i16m1(int16_t *a, int16_t *result, size_t length);
void vxor_vi_i32m1(int32_t *a, int32_t *result, size_t length);

void vxor_vi_i8m2(int8_t *a, int8_t *result, size_t length);
void vxor_vi_i16m2(int16_t *a, int16_t *result, size_t length);
void vxor_vi_i32m2(int32_t *a, int32_t *result, size_t length);

void vxor_vi_i8m4(int8_t *a, int8_t *result, size_t length);
void vxor_vi_i16m4(int16_t *a, int16_t *result, size_t length);
void vxor_vi_i32m4(int32_t *a, int32_t *result, size_t length);

void vxor_vi_i8m8(int8_t *a, int8_t *result, size_t length);
void vxor_vi_i16m8(int16_t *a, int16_t *result, size_t length);
void vxor_vi_i32m8(int32_t *a, int32_t *result, size_t length);


void vxor_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length);
void vxor_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length);
void vxor_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length);

void vxor_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length);
void vxor_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length);
void vxor_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length);

void vxor_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length);
void vxor_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length);
void vxor_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length);

void vxor_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length);
void vxor_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length);
void vxor_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length);


void vxor_vv_u8m1(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vxor_vv_u16m1(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vxor_vv_u32m1(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vxor_vv_u8m2(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vxor_vv_u16m2(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vxor_vv_u32m2(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vxor_vv_u8m4(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vxor_vv_u16m4(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vxor_vv_u32m4(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vxor_vv_u8m8(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vxor_vv_u16m8(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vxor_vv_u32m8(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);


void vxor_vi_u8m1(uint8_t *a, uint8_t *result, size_t length);
void vxor_vi_u16m1(uint16_t *a, uint16_t *result, size_t length);
void vxor_vi_u32m1(uint32_t *a, uint32_t *result, size_t length);

void vxor_vi_u8m2(uint8_t *a, uint8_t *result, size_t length);
void vxor_vi_u16m2(uint16_t *a, uint16_t *result, size_t length);
void vxor_vi_u32m2(uint32_t *a, uint32_t *result, size_t length);

void vxor_vi_u8m4(uint8_t *a, uint8_t *result, size_t length);
void vxor_vi_u16m4(uint16_t *a, uint16_t *result, size_t length);
void vxor_vi_u32m4(uint32_t *a, uint32_t *result, size_t length);

void vxor_vi_u8m8(uint8_t *a, uint8_t *result, size_t length);
void vxor_vi_u16m8(uint16_t *a, uint16_t *result, size_t length);
void vxor_vi_u32m8(uint32_t *a, uint32_t *result, size_t length);


void vxor_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vxor_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vxor_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vxor_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vxor_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vxor_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vxor_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vxor_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vxor_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vxor_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vxor_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vxor_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length);


/* --- vmul --- */
void vmul_vv_i8m1(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vmul_vv_i16m1(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vmul_vv_i32m1(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vmul_vv_i8m2(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vmul_vv_i16m2(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vmul_vv_i32m2(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vmul_vv_i8m4(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vmul_vv_i16m4(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vmul_vv_i32m4(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vmul_vv_i8m8(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vmul_vv_i16m8(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vmul_vv_i32m8(int32_t *a, int32_t *b, int32_t *result, size_t length);


void vmul_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length);
void vmul_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length);
void vmul_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length);

void vmul_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length);
void vmul_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length);
void vmul_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length);

void vmul_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length);
void vmul_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length);
void vmul_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length);

void vmul_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length);
void vmul_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length);
void vmul_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length);


void vmul_vv_u8m1(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vmul_vv_u16m1(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vmul_vv_u32m1(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vmul_vv_u8m2(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vmul_vv_u16m2(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vmul_vv_u32m2(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vmul_vv_u8m4(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vmul_vv_u16m4(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vmul_vv_u32m4(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vmul_vv_u8m8(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vmul_vv_u16m8(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vmul_vv_u32m8(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);


void vmul_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vmul_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vmul_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vmul_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vmul_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vmul_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vmul_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vmul_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vmul_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vmul_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vmul_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vmul_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length);


/* --- vmulh --- */
void vmulh_vv_i8m1(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vmulh_vv_i16m1(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vmulh_vv_i32m1(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vmulh_vv_i8m2(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vmulh_vv_i16m2(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vmulh_vv_i32m2(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vmulh_vv_i8m4(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vmulh_vv_i16m4(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vmulh_vv_i32m4(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vmulh_vv_i8m8(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vmulh_vv_i16m8(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vmulh_vv_i32m8(int32_t *a, int32_t *b, int32_t *result, size_t length);


void vmulh_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length);
void vmulh_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length);
void vmulh_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length);

void vmulh_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length);
void vmulh_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length);
void vmulh_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length);

void vmulh_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length);
void vmulh_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length);
void vmulh_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length);

void vmulh_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length);
void vmulh_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length);
void vmulh_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length);


/* --- vmulhu --- */
void vmulhu_vv_u8m1(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vmulhu_vv_u16m1(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vmulhu_vv_u32m1(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vmulhu_vv_u8m2(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vmulhu_vv_u16m2(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vmulhu_vv_u32m2(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vmulhu_vv_u8m4(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vmulhu_vv_u16m4(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vmulhu_vv_u32m4(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vmulhu_vv_u8m8(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vmulhu_vv_u16m8(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vmulhu_vv_u32m8(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);


void vmulhu_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vmulhu_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vmulhu_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vmulhu_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vmulhu_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vmulhu_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vmulhu_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vmulhu_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vmulhu_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vmulhu_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vmulhu_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vmulhu_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length);


/* --- vdiv --- */
void vdiv_vv_i8m1(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vdiv_vv_i16m1(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vdiv_vv_i32m1(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vdiv_vv_i8m2(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vdiv_vv_i16m2(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vdiv_vv_i32m2(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vdiv_vv_i8m4(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vdiv_vv_i16m4(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vdiv_vv_i32m4(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vdiv_vv_i8m8(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vdiv_vv_i16m8(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vdiv_vv_i32m8(int32_t *a, int32_t *b, int32_t *result, size_t length);


void vdiv_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length);
void vdiv_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length);
void vdiv_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length);

void vdiv_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length);
void vdiv_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length);
void vdiv_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length);

void vdiv_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length);
void vdiv_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length);
void vdiv_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length);

void vdiv_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length);
void vdiv_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length);
void vdiv_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length);


/* --- vdivu --- */
void vdivu_vv_u8m1(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vdivu_vv_u16m1(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vdivu_vv_u32m1(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vdivu_vv_u8m2(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vdivu_vv_u16m2(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vdivu_vv_u32m2(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vdivu_vv_u8m4(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vdivu_vv_u16m4(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vdivu_vv_u32m4(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vdivu_vv_u8m8(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vdivu_vv_u16m8(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vdivu_vv_u32m8(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);


void vdivu_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vdivu_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vdivu_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vdivu_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vdivu_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vdivu_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vdivu_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vdivu_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vdivu_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vdivu_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vdivu_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vdivu_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length);


/* --- vrem --- */
void vrem_vv_i8m1(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vrem_vv_i16m1(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vrem_vv_i32m1(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vrem_vv_i8m2(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vrem_vv_i16m2(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vrem_vv_i32m2(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vrem_vv_i8m4(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vrem_vv_i16m4(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vrem_vv_i32m4(int32_t *a, int32_t *b, int32_t *result, size_t length);

void vrem_vv_i8m8(int8_t *a, int8_t *b, int8_t *result, size_t length);
void vrem_vv_i16m8(int16_t *a, int16_t *b, int16_t *result, size_t length);
void vrem_vv_i32m8(int32_t *a, int32_t *b, int32_t *result, size_t length);


void vrem_vx_i8m1(int8_t *a, int8_t b, int8_t *result, size_t length);
void vrem_vx_i16m1(int16_t *a, int16_t b, int16_t *result, size_t length);
void vrem_vx_i32m1(int32_t *a, int32_t b, int32_t *result, size_t length);

void vrem_vx_i8m2(int8_t *a, int8_t b, int8_t *result, size_t length);
void vrem_vx_i16m2(int16_t *a, int16_t b, int16_t *result, size_t length);
void vrem_vx_i32m2(int32_t *a, int32_t b, int32_t *result, size_t length);

void vrem_vx_i8m4(int8_t *a, int8_t b, int8_t *result, size_t length);
void vrem_vx_i16m4(int16_t *a, int16_t b, int16_t *result, size_t length);
void vrem_vx_i32m4(int32_t *a, int32_t b, int32_t *result, size_t length);

void vrem_vx_i8m8(int8_t *a, int8_t b, int8_t *result, size_t length);
void vrem_vx_i16m8(int16_t *a, int16_t b, int16_t *result, size_t length);
void vrem_vx_i32m8(int32_t *a, int32_t b, int32_t *result, size_t length);


/* --- vremu --- */
void vremu_vv_u8m1(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vremu_vv_u16m1(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vremu_vv_u32m1(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vremu_vv_u8m2(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vremu_vv_u16m2(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vremu_vv_u32m2(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vremu_vv_u8m4(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vremu_vv_u16m4(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vremu_vv_u32m4(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);

void vremu_vv_u8m8(uint8_t *a, uint8_t *b, uint8_t *result, size_t length);
void vremu_vv_u16m8(uint16_t *a, uint16_t *b, uint16_t *result, size_t length);
void vremu_vv_u32m8(uint32_t *a, uint32_t *b, uint32_t *result, size_t length);


void vremu_vx_u8m1(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vremu_vx_u16m1(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vremu_vx_u32m1(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vremu_vx_u8m2(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vremu_vx_u16m2(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vremu_vx_u32m2(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vremu_vx_u8m4(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vremu_vx_u16m4(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vremu_vx_u32m4(uint32_t *a, uint32_t b, uint32_t *result, size_t length);

void vremu_vx_u8m8(uint8_t *a, uint8_t b, uint8_t *result, size_t length);
void vremu_vx_u16m8(uint16_t *a, uint16_t b, uint16_t *result, size_t length);
void vremu_vx_u32m8(uint32_t *a, uint32_t b, uint32_t *result, size_t length);


#ifdef __cplusplus
}
#endif

