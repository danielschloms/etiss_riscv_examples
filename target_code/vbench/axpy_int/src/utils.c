#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>
#include <assert.h>
#include "utils.h"


float capture_ref_result(float a, float* dx, float* dy, int n)
{
   float result = a*dx[0] + dy[0];
   // result will be the same for all vector
   return result;
}


void test_result(float *y, float y_ref, long nrows)
{
   long row;
   const float epsilon = 0.0001;
   const float epsilon_double = 0.0000001;
   int nerrs=0;
   /* Compute with the result to keep the compiler for marking the code as dead */
   for (row=0; row<nrows; row++) {
      float error = y[row] - y_ref;
      if (fabs(error) > epsilon)  {
         printf("y[%ld]=%.16f != y_ref[%ld]=%.16f  INCORRECT RESULT !!!! \n ", row, y[row], row, y_ref);
         nerrs++;
         if (nerrs == 100) break;
      }
   }
   if (nerrs == 0) printf ("Result ok !!!\n");
   return;
}

void init_vector(float *pv, long n, float value)
{
   for (int i=0; i<n; i++) pv[i]= value;
}