void NDPluginFFT::processCallbacks(NDArray *pArray)
{
  //This function is called with the mutex already locked.  
  //It unlocks it during long calculations when private structures don't need to be protected.

  int nTimeX, nTimeY;
  int numAverage;
  int numAveraged;
  int resetAverage;
  double timePerPoint;  
  const char* functionName = "NDPluginFFT::processCallbacks";

  /* Call the base class method */
  NDPluginDriver::processCallbacks(pArray);

  // This plugin only works with 1-D or 2-D arrays
  switch (pArray->ndims) {
    case 1:
      rank_ = 1;
      nTimeX = (int)pArray->dims[0].size;
      nTimeY = 1;
      break;
    case 2:
      rank_ = 2;
      nTimeX = (int)pArray->dims[0].size;
      nTimeY = (int)pArray->dims[1].size;
      break;
    default:
      asynPrint(pasynUserSelf, ASYN_TRACE_ERROR,
        "%s: error, number of array dimensions must be 1 or 2\n",
        functionName);
      return;
      break;
  }
  if ((nTimeX != nTimeXIn_) ||
      (nTimeY != nTimeYIn_)) {
    nTimeXIn_ = nTimeX;
    nTimeYIn_ = nTimeY;
    allocateArrays();
  }

  getDoubleParam(P_FFTTimePerPoint, &timePerPoint);
  if (timePerPoint != timePerPoint_) {
    timePerPoint_ = timePerPoint;
    createAxisArrays();
  }

  getIntegerParam(P_FFTSuppressDC,   &suppressDC_);
  getIntegerParam(P_FFTResetAverage, &resetAverage);
  getIntegerParam(P_FFTNumAverage,   &numAverage);
  getIntegerParam(P_FFTNumAveraged,  &numAveraged);
  if (resetAverage) {
    setIntegerParam(P_FFTResetAverage, 0);
    numAveraged = 1;
  }
  if (numAverage != numAverage_) {
    numAverage_ = numAverage;
    numAveraged = 1;
  }
  
  oldFraction_ = 1. - 1./numAveraged;
  newFraction_ = 1./numAveraged;
  if (numAveraged < numAverage) numAveraged++;
  setIntegerParam(P_FFTNumAveraged, numAveraged);

  switch(pArray->dataType) {
  case NDInt8:
    convertToDoubleT<epicsInt8>(pArray);
    break;
  case NDUInt8:
    convertToDoubleT<epicsUInt8>(pArray);
    break;
  case NDInt16:
    convertToDoubleT<epicsInt16>(pArray);
    break;
  case NDUInt16:
    convertToDoubleT<epicsUInt16>(pArray);
    break;
  case NDInt32:
    convertToDoubleT<epicsInt32>(pArray);
    break;
  case NDUInt32:
    convertToDoubleT<epicsUInt32>(pArray);
    break;
  case NDFloat32:
    convertToDoubleT<epicsFloat32>(pArray);
    break;
  case NDFloat64:
    convertToDoubleT<epicsFloat64>(pArray);
    break;
  default:
    break;
  }
  if (rank_ == 1) computeFFT_1D();
  if (rank_ == 2) computeFFT_2D();

  callParamCallbacks();
}