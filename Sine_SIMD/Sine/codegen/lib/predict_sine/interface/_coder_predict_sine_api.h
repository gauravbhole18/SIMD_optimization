/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_predict_sine_api.h
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 16-Dec-2024 20:38:27
 */

#ifndef _CODER_PREDICT_SINE_API_H
#define _CODER_PREDICT_SINE_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
real32_T predict_sine(real32_T Theta1[32], real32_T Theta2[272],
                      real32_T Theta3[17], real_T X);

void predict_sine_api(const mxArray *const prhs[4], const mxArray **plhs);

void predict_sine_atexit(void);

void predict_sine_initialize(void);

void predict_sine_terminate(void);

void predict_sine_xil_shutdown(void);

void predict_sine_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_predict_sine_api.h
 *
 * [EOF]
 */
