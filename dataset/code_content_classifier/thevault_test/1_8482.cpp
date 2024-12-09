NDPluginFFT::NDPluginFFT(const char *portName, int queueSize, int blockingCallbacks,
                         const char *NDArrayPort, int NDArrayAddr, 
                         int maxBuffers, size_t maxMemory,
                         int priority, int stackSize)
    /* Invoke the base class constructor */
    : NDPluginDriver(portName, queueSize, blockingCallbacks,
             NDArrayPort, NDArrayAddr, 1, NUM_NDPLUGIN_FFT_PARAMS, maxBuffers, maxMemory,
             asynFloat64Mask | asynFloat64ArrayMask | asynGenericPointerMask,
             asynFloat64Mask | asynFloat64ArrayMask | asynGenericPointerMask,
             0, 1, priority, stackSize),
    uniqueId_(0), timePerPoint_(0), timeAxis_(0), freqAxis_(0), timeSeries_(0), 
    FFTReal_(0), FFTImaginary_(0), FFTAbsValue_(0)
{
  //const char *functionName = "NDPluginFFT::NDPluginFFT";

  createParam(FFTTimeAxisString,         asynParamFloat64Array, &P_FFTTimeAxis);
  createParam(FFTFreqAxisString,         asynParamFloat64Array, &P_FFTFreqAxis);
  createParam(FFTTimePerPointString,          asynParamFloat64, &P_FFTTimePerPoint);
  createParam(FFTDirectionString,               asynParamInt32, &P_FFTDirection);
  createParam(FFTSuppressDCString,              asynParamInt32, &P_FFTSuppressDC);
  createParam(FFTNumAverageString,              asynParamInt32, &P_FFTNumAverage);
  createParam(FFTNumAveragedString,             asynParamInt32, &P_FFTNumAveraged);
  createParam(FFTResetAverageString,            asynParamInt32, &P_FFTResetAverage);
  
  createParam(FFTTimeSeriesString,       asynParamFloat64Array, &P_FFTTimeSeries);
  createParam(FFTRealString,             asynParamFloat64Array, &P_FFTReal);
  createParam(FFTImaginaryString,        asynParamFloat64Array, &P_FFTImaginary);
  createParam(FFTAbsValueString,         asynParamFloat64Array, &P_FFTAbsValue);
 
  /* Set the plugin type string */
  setStringParam(NDPluginDriverPluginType, "NDPluginFFT");
  
  /* Try to connect to the array port */
  connectToArrayPort();

  callParamCallbacks();
  
}