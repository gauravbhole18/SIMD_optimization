/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predict_sine.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 16-Dec-2024 20:38:27
 */

/* Include Files */
#include "predict_sine.h"
#include <immintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * PREDICT Predict the label of an input given a trained neural network
 *    p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
 *    trained weights of a neural network (Theta1, Theta2)
 *
 * Arguments    : const float Theta1[32]
 *                const float Theta2[272]
 *                const float Theta3[17]
 *                double X
 * Return Type  : float
 */
float predict_sine(const float Theta1[32], const float Theta2[272],
                   const float Theta3[17], double X)
{
  float fv[17];
  float w1[16];
  float p;
  int i;
  int k;
  /* ReLU function */
  fv[0] = 1.0F;
  for (k = 0; k <= 8; k += 8) {
    __m256 r;
    __m256 r1;
    r = _mm256_loadu_ps(&Theta1[k + 16]);
    r = _mm256_mul_ps(r, _mm256_set1_ps((float)X));
    r1 = _mm256_loadu_ps(&Theta1[k]);
    r = _mm256_add_ps(r1, r);
    r = _mm256_blendv_ps(
        r,
        _mm256_blendv_ps(_mm256_set1_ps(0.0F), r,
                         _mm256_cmp_ps(r, _mm256_set1_ps(0.0F), 29)),
        _mm256_cmp_ps(_mm256_set1_ps(0.0F), _mm256_set1_ps(0.0F), 7));
    _mm256_storeu_ps(&fv[k + 1], r);
  }
  for (k = 0; k < 16; k++) {
    float f;
    f = 0.0F;
    for (i = 0; i < 17; i++) {
      f += Theta2[k + (i << 4)] * fv[i];
    }
    w1[k] = fmaxf(f, 0.0F);
  }
  fv[0] = 1.0F;
  memcpy(&fv[1], &w1[0], 16U * sizeof(float));
  p = 0.0F;
  for (i = 0; i < 17; i++) {
    p += Theta3[i] * fv[i];
  }
  /*  =========================================================================
   */
  return p;
}

/*
 * File trailer for predict_sine.c
 *
 * [EOF]
 */
