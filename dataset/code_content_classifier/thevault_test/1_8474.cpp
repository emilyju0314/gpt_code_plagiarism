asynStatus  NDPluginStats::writeFloat64(asynUser *pasynUser, epicsFloat64 value)
{
    int function = pasynUser->reason;
    asynStatus status = asynSuccess;
    int computeCentroid, computeProfiles;
    static const char *functionName = "writeFloat64";

    /* Set the parameter and readback in the parameter library.  This may be overwritten when we read back the
     * status at the end, but that's OK */
    status = setDoubleParam(function, value);

    if (function == NDPluginStatsCentroidThreshold) {
        getIntegerParam(NDPluginStatsComputeCentroid, &computeCentroid);
        if (computeCentroid && this->pArrays[0]) {
            doComputeCentroid(this->pArrays[0]);
            getIntegerParam(NDPluginStatsComputeProfiles, &computeProfiles);
            if (computeProfiles) doComputeProfiles(this->pArrays[0]);
        }
    } else {
        /* If this parameter belongs to a base class call its method */
        if (function < FIRST_NDPLUGIN_STATS_PARAM) status = NDPluginDriver::writeFloat64(pasynUser, value);
    }

    /* Do callbacks so higher layers see any changes */
    callParamCallbacks();
    if (status) 
        asynPrint(pasynUser, ASYN_TRACE_ERROR, 
              "%s:%s: error, status=%d function=%d, value=%f\n", 
              driverName, functionName, status, function, value);
    else        
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
              "%s:%s: function=%d, value=%f\n", 
              driverName, functionName, function, value);
    return status;
}