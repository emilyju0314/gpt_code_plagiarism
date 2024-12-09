NDPluginStats::NDPluginStats(const char *portName, int queueSize, int blockingCallbacks,
                         const char *NDArrayPort, int NDArrayAddr,
                         int maxBuffers, size_t maxMemory,
                         int priority, int stackSize)
    /* Invoke the base class constructor */
    : NDPluginDriver(portName, queueSize, blockingCallbacks,
                   NDArrayPort, NDArrayAddr, 1, NUM_NDPLUGIN_STATS_PARAMS, maxBuffers, maxMemory,
                   asynInt32ArrayMask | asynFloat64ArrayMask | asynGenericPointerMask,
                   asynInt32ArrayMask | asynFloat64ArrayMask | asynGenericPointerMask,
                   0, 1, priority, stackSize)
{
    int numTSPoints=256;  // Initial size of time series
    int i;
    //static const char *functionName = "NDPluginStats";
    
    /* Statistics */
    createParam(NDPluginStatsComputeStatisticsString, asynParamInt32,      &NDPluginStatsComputeStatistics);
    createParam(NDPluginStatsBgdWidthString,          asynParamInt32,      &NDPluginStatsBgdWidth);
    createParam(NDPluginStatsMinValueString,          asynParamFloat64,    &NDPluginStatsMinValue);
    createParam(NDPluginStatsMinXString,              asynParamFloat64,    &NDPluginStatsMinX);
    createParam(NDPluginStatsMinYString,              asynParamFloat64,    &NDPluginStatsMinY);            
    createParam(NDPluginStatsMaxValueString,          asynParamFloat64,    &NDPluginStatsMaxValue);
    createParam(NDPluginStatsMaxXString,              asynParamFloat64,    &NDPluginStatsMaxX);
    createParam(NDPluginStatsMaxYString,              asynParamFloat64,    &NDPluginStatsMaxY);                
    createParam(NDPluginStatsMeanValueString,         asynParamFloat64,    &NDPluginStatsMeanValue);
    createParam(NDPluginStatsSigmaValueString,        asynParamFloat64,    &NDPluginStatsSigmaValue);
    createParam(NDPluginStatsTotalString,             asynParamFloat64,    &NDPluginStatsTotal);
    createParam(NDPluginStatsNetString,               asynParamFloat64,    &NDPluginStatsNet);

    /* Centroid */
    createParam(NDPluginStatsComputeCentroidString,   asynParamInt32,      &NDPluginStatsComputeCentroid);
    createParam(NDPluginStatsCentroidThresholdString, asynParamFloat64,    &NDPluginStatsCentroidThreshold);
    createParam(NDPluginStatsCentroidXString,         asynParamFloat64,    &NDPluginStatsCentroidX);
    createParam(NDPluginStatsCentroidYString,         asynParamFloat64,    &NDPluginStatsCentroidY);
    createParam(NDPluginStatsSigmaXString,            asynParamFloat64,    &NDPluginStatsSigmaX);
    createParam(NDPluginStatsSigmaYString,            asynParamFloat64,    &NDPluginStatsSigmaY);
    createParam(NDPluginStatsSigmaXYString,           asynParamFloat64,    &NDPluginStatsSigmaXY);

    /* Time series */
    createParam(NDPluginStatsTSControlString,         asynParamInt32,        &NDPluginStatsTSControl);
    createParam(NDPluginStatsTSNumPointsString,       asynParamInt32,        &NDPluginStatsTSNumPoints);
    createParam(NDPluginStatsTSCurrentPointString,    asynParamInt32,        &NDPluginStatsTSCurrentPoint);
    createParam(NDPluginStatsTSAcquiringString,       asynParamInt32,        &NDPluginStatsTSAcquiring);
    createParam(NDPluginStatsTSMinValueString,        asynParamFloat64Array, &NDPluginStatsTSMinValue);
    createParam(NDPluginStatsTSMinXString,            asynParamFloat64Array, &NDPluginStatsTSMinX);
    createParam(NDPluginStatsTSMinYString,            asynParamFloat64Array, &NDPluginStatsTSMinY);            
    createParam(NDPluginStatsTSMaxValueString,        asynParamFloat64Array, &NDPluginStatsTSMaxValue);
    createParam(NDPluginStatsTSMaxXString,            asynParamFloat64Array, &NDPluginStatsTSMaxX);
    createParam(NDPluginStatsTSMaxYString,            asynParamFloat64Array, &NDPluginStatsTSMaxY);                
    createParam(NDPluginStatsTSMeanValueString,       asynParamFloat64Array, &NDPluginStatsTSMeanValue);
    createParam(NDPluginStatsTSSigmaValueString,      asynParamFloat64Array, &NDPluginStatsTSSigmaValue);
    createParam(NDPluginStatsTSTotalString,           asynParamFloat64Array, &NDPluginStatsTSTotal);
    createParam(NDPluginStatsTSNetString,             asynParamFloat64Array, &NDPluginStatsTSNet);
    createParam(NDPluginStatsTSCentroidXString,       asynParamFloat64Array, &NDPluginStatsTSCentroidX);
    createParam(NDPluginStatsTSCentroidYString,       asynParamFloat64Array, &NDPluginStatsTSCentroidY);
    createParam(NDPluginStatsTSSigmaXString,          asynParamFloat64Array, &NDPluginStatsTSSigmaX);
    createParam(NDPluginStatsTSSigmaYString,          asynParamFloat64Array, &NDPluginStatsTSSigmaY);
    createParam(NDPluginStatsTSSigmaXYString,         asynParamFloat64Array, &NDPluginStatsTSSigmaXY);
    createParam(NDPluginStatsTSTimestampString,       asynParamFloat64Array, &NDPluginStatsTSTimestamp);

    /* Profiles */
    createParam(NDPluginStatsComputeProfilesString,   asynParamInt32,         &NDPluginStatsComputeProfiles);
    createParam(NDPluginStatsProfileSizeXString,      asynParamInt32,         &NDPluginStatsProfileSizeX);
    createParam(NDPluginStatsProfileSizeYString,      asynParamInt32,         &NDPluginStatsProfileSizeY);
    createParam(NDPluginStatsCursorXString,           asynParamInt32,         &NDPluginStatsCursorX);
    createParam(NDPluginStatsCursorYString,           asynParamInt32,         &NDPluginStatsCursorY);
    createParam(NDPluginStatsProfileAverageXString,   asynParamFloat64Array,  &NDPluginStatsProfileAverageX);
    createParam(NDPluginStatsProfileAverageYString,   asynParamFloat64Array,  &NDPluginStatsProfileAverageY);
    createParam(NDPluginStatsProfileThresholdXString, asynParamFloat64Array,  &NDPluginStatsProfileThresholdX);
    createParam(NDPluginStatsProfileThresholdYString, asynParamFloat64Array,  &NDPluginStatsProfileThresholdY);
    createParam(NDPluginStatsProfileCentroidXString,  asynParamFloat64Array,  &NDPluginStatsProfileCentroidX);
    createParam(NDPluginStatsProfileCentroidYString,  asynParamFloat64Array,  &NDPluginStatsProfileCentroidY);
    createParam(NDPluginStatsProfileCursorXString,    asynParamFloat64Array,  &NDPluginStatsProfileCursorX);
    createParam(NDPluginStatsProfileCursorYString,    asynParamFloat64Array,  &NDPluginStatsProfileCursorY);

    /* Histogram */
    createParam(NDPluginStatsComputeHistogramString,  asynParamInt32,         &NDPluginStatsComputeHistogram);
    createParam(NDPluginStatsHistSizeString,          asynParamInt32,         &NDPluginStatsHistSize);
    createParam(NDPluginStatsHistMinString,           asynParamFloat64,       &NDPluginStatsHistMin);
    createParam(NDPluginStatsHistMaxString,           asynParamFloat64,       &NDPluginStatsHistMax);
    createParam(NDPluginStatsHistEntropyString,       asynParamFloat64,       &NDPluginStatsHistEntropy);
    createParam(NDPluginStatsHistArrayString,         asynParamFloat64Array,  &NDPluginStatsHistArray);

    memset(this->profileX, 0, sizeof(this->profileX));
    memset(this->profileY, 0, sizeof(this->profileY));
    // If we uncomment the following line then we can't set numTSPoints from database at initialisation
    //setIntegerParam(NDPluginStatsTSNumPoints, numTSPoints);
    setIntegerParam(NDPluginStatsTSAcquiring, 0);
    setIntegerParam(NDPluginStatsTSCurrentPoint, 0);
    for (i=0; i<MAX_TIME_SERIES_TYPES; i++) {
        timeSeries[i] = (double *)calloc(numTSPoints, sizeof(double));
    }
    this->histogram = NULL;

    /* Set the plugin type string */
    setStringParam(NDPluginDriverPluginType, "NDPluginStats");

    /* Try to connect to the array port */
    connectToArrayPort();
}