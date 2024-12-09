asynStatus NDPluginStats::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    asynStatus status = asynSuccess;
    int i;
    int numPoints, currentPoint;
    static const char *functionName = "writeInt32";


    /* Set the parameter in the parameter library. */
    status = (asynStatus) setIntegerParam(function, value);

    if (function == NDPluginStatsCursorX) {
        this->cursorX = value;
        if (this->pArrays[0]) {
            doComputeProfiles(this->pArrays[0]);
        }
    } else if (function == NDPluginStatsCursorY) {
        this->cursorY = value;
        if (this->pArrays[0]) {
            doComputeProfiles(this->pArrays[0]);
        }
    } else if (function == NDPluginStatsTSNumPoints) {
        for (i=0; i<MAX_TIME_SERIES_TYPES; i++) {
            free(this->timeSeries[i]);
            timeSeries[i] = (double *)calloc(value, sizeof(double));
        }
    } else if (function == NDPluginStatsTSControl) {
        switch (value) {
            case TSEraseStart:
                setIntegerParam(NDPluginStatsTSCurrentPoint, 0);
                setIntegerParam(NDPluginStatsTSAcquiring, 1);
                getIntegerParam(NDPluginStatsTSNumPoints, &numPoints);
                for (i=0; i<MAX_TIME_SERIES_TYPES; i++) {
                    memset(this->timeSeries[i], 0, numPoints*sizeof(double));
                }
                break;
            case TSStart:
                getIntegerParam(NDPluginStatsTSNumPoints, &numPoints);
                getIntegerParam(NDPluginStatsTSCurrentPoint, &currentPoint);
                if (currentPoint < numPoints) {
                    setIntegerParam(NDPluginStatsTSAcquiring, 1);
                }
                break;
            case TSStop:
                setIntegerParam(NDPluginStatsTSAcquiring, 0);
                doTimeSeriesCallbacks();
                break;
            case TSRead:
                doTimeSeriesCallbacks();
                break;
        }
    } else {
        /* If this parameter belongs to a base class call its method */
        if (function < FIRST_NDPLUGIN_STATS_PARAM) 
            status = NDPluginDriver::writeInt32(pasynUser, value);
    }
    
    /* Do callbacks so higher layers see any changes */
    status = (asynStatus) callParamCallbacks();
    
    if (status) 
        epicsSnprintf(pasynUser->errorMessage, pasynUser->errorMessageSize, 
                  "%s:%s: status=%d, function=%d, value=%d", 
                  driverName, functionName, status, function, value);
    else        
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
              "%s:%s: function=%d, value=%d\n", 
              driverName, functionName, function, value);
    return status;
}