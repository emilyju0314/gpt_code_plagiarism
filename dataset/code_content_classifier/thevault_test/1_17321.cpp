TfLiteRegistration* Register_CONV_2D_UINT8() {
#if defined TFLITE_WITH_RUY_ONLY
  // TFLITE_WITH_RUY_ONLY optimizes the generic kernel type.
  return Register_CONVOLUTION_GENERIC_OPT_UINT8();
#else
  return Register_CONV_2D();
#endif
}