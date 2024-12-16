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
#include <stdio.h>

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
 float temp[272] = {-3.072332e-01,8.140789e-01,-3.477814e-02,1.780647e-01,2.540483e-01,0,-6.375670e-01,0,-2.297895e-01,5.732973e-01,1.161225e-01,2.823185e-01,0,2.541243e-01,2.728134e-01,4.516693e-02,-1.158850e-01,-8.301947e-02,-2.599310e-01,5.496376e-02,1.481563e-03,3.286529e-01,-3.157955e-01,7.810906e-03,-1.667518e-01,2.044439e-01,-3.958243e-01,-3.247892e-01,-4.740387e-03,4.622076e-01,5.806482e-02,4.146331e-01,6.381780e-03,-1.583257e+00,-4.751900e-01,8.523207e-03,-3.614016e-01,3.157423e-01,-9.287128e-02,-5.605966e-01,1.771618e-01,6.567305e-02,3.237025e-01,3.066443e-01,1.055584e-01,3.609694e-01,-3.840364e-01,2.759124e-01,2.273240e-01,7.204202e-02,-2.269990e-01,-3.044964e-01,-2.936479e-01,-4.234412e-01,2.926901e-01,-6.049970e-02,-3.450556e-01,-3.432305e-01,6.024601e-02,2.899485e-01,4.274945e-01,-2.409955e-01,1.992600e-01,3.368113e-01,3.988353e-01,-1.227600e-01,1.395817e-02,3.441741e-01,1.825697e-01,-3.631264e-02,1.868236e-01,-2.314427e-01,-7.725445e-02,-3.353031e-01,3.184853e-01,3.090799e-01,-2.972664e-01,1.496988e-01,-3.003078e-01,7.406089e-02,-1.826822e-01,1.636427e-01,3.036568e-01,2.194433e-01,4.153419e-01,3.570470e-01,2.435640e-01,-1.193670e-01,1.998878e-01,6.844679e-02,9.627026e-02,1.987438e-01,2.196668e-01,-4.218870e-01,-1.355155e-01,1.999224e-01,-2.024374e-01,3.971120e-01,-7.735169e-02,-3.808051e-01,1.782316e-02,-1.889066e-01,3.460049e-01,-2.502502e-01,-3.341929e-01,-3.082363e-01,-1.961226e-01,3.373173e-01,-1.337199e-01,2.833489e-02,-4.324920e-01,-1.109425e-01,1.165842e-01,7.380231e-01,4.946102e-01,-1.330758e-01,3.054687e-01,1.035476e-01,4.279272e-01,5.835642e-02,-1.537160e-02,-2.963074e-01,-6.890790e-01,5.348921e-02,6.719407e-02,1.274534e-01,2.113101e-02,3.654049e-01,2.282806e-01,2.089236e-01,-2.380530e-01,-2.356696e-01,-6.541538e-02,-9.723902e-04,2.543449e-02,-2.265779e-01,3.024136e-01,-3.679548e-01,-2.865306e-02,-4.014065e-01,2.982988e-01,5.009824e-02,-1.241452e-02,-8.630824e-02,-2.868551e-01,3.796829e-01,1.375554e-03,1.622603e-01,3.368457e-01,2.464671e-01,-6.746909e-02,4.301866e-01,-2.220428e-01,1.802123e-01,-3.642807e-01,4.196815e-01,-3.269090e-01,4.661664e-02,-1.270725e-01,-3.831167e-01,-4.024726e-01,3.615549e-01,2.688027e-01,5.331249e-01,-4.243085e-01,-5.905145e-02,6.132105e-02,-6.226369e-01,2.608137e-01,3.850982e-01,-7.978372e-02,-3.035204e-01,-2.221146e-01,-4.082081e-01,-9.219807e-02,1.321581e-01,2.552649e-01,1.294115e-01,-1.748946e-01,-2.111483e-01,-3.637421e-01,-9.150427e-01,2.119015e-01,-5.776882e-01,7.230458e-02,1.486485e-01,4.552668e-01,-1.639762e-01,1.315116e-01,-8.049642e-01,-3.877640e-03,-4.048753e-01,-4.149153e-01,-5.027102e-01,-2.525172e-01,-1.278658e-01,3.133327e-01,-1.952283e-01,-4.980317e-02,3.776356e-01,-7.292683e-02,-2.558908e-01,1.457656e-01,3.803723e-01,-1.094724e-01,2.447934e-03,5.367079e-02,-2.899602e-02,2.571451e-01,-1.279143e-01,-2.089086e-01,-7.106882e-02,-1.521835e-02,1.951538e-01,1.617033e-01,-1.203431e-01,-2.499843e-02,1.868841e-02,-9.199685e-02,2.316227e-01,1.819334e-01,-1.220572e-01,-3.631072e-01,1.075488e-01,1.092972e-01,1.150586e-01,1.104164e-01,-3.765243e-01,-4.177748e-01,-4.022106e-01,-2.531403e-01,3.392858e-01,3.722979e-01,-8.071458e-02,2.113906e-01,-1.825097e-01,-2.603438e-01,2.963207e-01,2.179275e-01,1.652873e-01,9.910986e-02,-3.051606e-01,2.951877e-01,1.231085e-02,1.124990e-01,-2.502296e-02,-3.875985e-01,5.877992e-02,-2.403977e-01,-4.166392e-01,5.036135e-03,-3.371359e-01,3.835245e-01,-6.341115e-02,-1.966326e-01,-2.877613e-01,-2.372229e-02,-4.400971e-01,-3.581959e-01,5.511913e-02,-2.870423e-01,7.661054e-02,1.818625e-01,1.329114e-01,2.020204e-01,-3.691870e-01,-1.224706e-01,-8.097029e-02,-9.584725e-04,-6.088076e-02,1.938881e-01,-7.909673e-02};
  for (i = 0; i < 272; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = temp[i];
  }
}

/*
 * Arguments    : float result[32]
 * Return Type  : void
 */
static void argInit_16x2_real32_T(float result[32])
{
  int i;
  float temp[32] = {0,-5.620929e-01,-2.445755e-01,8.363335e-02,0,-2.902618e-03,0,-2.269882e-01,-3.162274e-03,0,8.779509e-01,0,0,-2.718611e-03,0,0,-4.180086e-01,2.426115e-01,1.769394e-01,-2.361339e-02,-2.041357e-01,2.875382e-01,-3.857099e-01,4.492213e-01,-7.588696e-05,-6.736517e-04,2.456712e-02,-5.058061e-01,-4.907290e-01,2.736533e-01,-2.608642e-01,-2.025218e-01};

  /* Loop over the array to initialize each element. */
  for (i = 0; i < 32; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = temp[i];
  }
}

/*
 * Arguments    : float result[17]
 * Return Type  : void
 */
static void argInit_1x17_real32_T(float result[17])
{
  int idx1;
  float temp[17] = {-2.895313e-01,1.352455e-01,1.880445e+00,4.918047e-01,-2.934478e-01,-2.775381e-01,5.026222e-01,2.203315e+00,-2.419147e-01,2.695560e-01,-1.328556e+00,-6.181847e-01,-5.708671e-01,1.849502e-02,-4.414673e-01,-2.489600e-01,-1.101300e-03};

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 17; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = temp[idx1];
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
  p = predict_sine(fv, fv1, fv2, 0);
  printf("Predicted sine value: %f\n", p);
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
