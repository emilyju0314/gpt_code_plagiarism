OMXFFTSpec_R_F32* CreateOpenmaxState(int order) {
  RTC_CHECK_GE(order, 1);
  // The omx implementation uses this macro to check order validity.
  RTC_CHECK_LE(order, TWIDDLE_TABLE_ORDER);

  OMX_INT buffer_size;
  OMXResult r = omxSP_FFTGetBufSize_R_F32(order, &buffer_size);
  RTC_CHECK_EQ(r, OMX_Sts_NoErr);

  OMXFFTSpec_R_F32* omx_spec = malloc(buffer_size);
  RTC_DCHECK(omx_spec);

  r = omxSP_FFTInit_R_F32(omx_spec, order);
  RTC_CHECK_EQ(r, OMX_Sts_NoErr);
  return omx_spec;
}