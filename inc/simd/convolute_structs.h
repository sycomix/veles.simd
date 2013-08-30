/*! @file convolute_structs.h
 *  @brief New file description.
 *  @author Markovtsev Vadim <v.markovtsev@samsung.com>
 *  @version 1.0
 *
 *  @section Notes
 *  This code partially conforms to <a href="http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml">Google C++ Style Guide</a>.
 *
 *  @section Copyright
 *  Copyright 2013 Samsung R&D Institute Russia
 */

#ifndef INC_SIMD_CONVOLUTE_STRUCTS_H_
#define INC_SIMD_CONVOLUTE_STRUCTS_H_

#include <stddef.h>

#if __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

struct ConvoluteOverlapSaveHandle {
  void *fft_plan;
  void *fft_inverse_plan;
  float *fft_boiler_plate;
  float *H;
  size_t x_length;
  size_t h_length;
  int *L;
  int reverse;
};

struct ConvoluteFFTHandle {
  void *fft_plan;
  void *fft_inverse_plan;
  int *M;
  int x_length;
  int h_length;
  float **inputs;
  int reverse;
};

typedef enum {
  kConvolutionAlgorithmBruteForce,
  kConvolutionAlgorithmFFT,
  kConvolutionAlgorithmOverlapSave
} ConvolutionAlgorithm;

struct ConvoluteHandle {
  ConvolutionAlgorithm algorithm;
  int x_length;
  int h_length;
  union {
    struct ConvoluteFFTHandle fft;
    struct ConvoluteOverlapSaveHandle os;
  } handle;
};

#if __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif  // INC_SIMD_CONVOLUTE_STRUCTS_H_
