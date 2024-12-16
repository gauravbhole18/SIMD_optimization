/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 24.1
 * C/C++ source code generated on  : 16-Dec-2024 20:38:27
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "predict_sine.h"
#include "predict_sine_terminate.h"

/* Function Declarations */
static void argInit_16x17_real32_T(float result[272]);

static void argInit_16x2_real32_T(float result[32]);

static void argInit_1x17_real32_T(float result[17]);

static float argInit_real32_T(void);

static double argInit_real_T(void);

/* Function Definitions */
/*
 * Arguments    : float result[272]
 * Return Type  : void
 */
static void argInit_16x17_real32_T(float result[272])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 272; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real32_T();
  }
}

/*
 * Arguments    : float result[32]
 * Return Type  : void
 */
static void argInit_16x2_real32_T(float result[32])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 32; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real32_T();
  }
}

/*
 * Arguments    : float result[17]
 * Return Type  : void
 */
static void argInit_1x17_real32_T(float result[17])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 17; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real32_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : float
 */
static float argInit_real32_T(void)
{
  return 0.0F;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_predict_sine();
  /* Terminate the application.
You do not need to do this more than one time. */
  predict_sine_terminate();
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void main_predict_sine(void)
{
  float fv1[272];
  float fv[32];
  float fv2[17];
  float p;
  /* Initialize function 'predict_sine' input arguments. */
  /* Initialize function input argument 'Theta1'. */
  /* Initialize function input argument 'Theta2'. */
  /* Initialize function input argument 'Theta3'. */
  /* Call the entry-point 'predict_sine'. */
  argInit_16x2_real32_T(fv);
  argInit_16x17_real32_T(fv1);
  argInit_1x17_real32_T(fv2);
  p = predict_sine(fv, fv1, fv2, argInit_real_T());
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
