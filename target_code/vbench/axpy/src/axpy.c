/*************************************************************************
* Vectorized Axpy Kernel
* Author: Jesus Labarta
* Barcelona Supercomputing Center
*************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#ifdef USE_RISCV_VECTOR
#include <riscv_vector.h>
#include "../../vector_defines.h"
#endif

#ifndef USE_RISCV_VECTOR

void axpy_serial(float a, float *dx, float *dy, int n) {
   int i;
   for (i=0; i<n; i++) {
      dy[i] += a*dx[i];
   }
}

#else

void axpy_vector(float a, float *dx, float *dy, int n) {
  int i;
  printf("Hello Vector!\n");

  long gvl = _MMR_VSETVL_E32M1(n);
  
  for (i = 0; i < n;) {
    gvl = _MMR_VSETVL_E32M1(n - i);
    vfloat32m1_t v_dx = _MM_LOAD_f32(&dx[i], gvl);
    vfloat32m1_t v_dy = _MM_LOAD_f32(&dy[i], gvl);
    vfloat32m1_t v_res = _MM_MACC_VF_f32(v_dy, a, v_dx, gvl);
    _MM_STORE_f32(&dy[i], v_res, gvl);

    i += gvl;
  }
}

#endif