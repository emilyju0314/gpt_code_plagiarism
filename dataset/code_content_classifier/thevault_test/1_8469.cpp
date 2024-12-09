asynStatus NDPluginDriver::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
    int function = pasynUser->reason;
    int addr=0;
    asynStatus status = asynSuccess;
    static const char* functionName = "writeInt32";

    status = getAddress(pasynUser, &addr); if (status != asynSuccess) return(status);

    /* Set the parameter in the parameter library. */
    status = (asynStatus) setIntegerParam(addr, function, value);

    if (function == NDPluginDriverEnableCallbacks) {
        if (value) {  
            if (this->connectedToArrayPort) {
                /* We need to register to be called with interrupts from the detector driver on 
                 * the asynGenericPointer interface. Must do this with the lock released. */
                this->unlock();
                status = setArrayInterrupt(1);
                this->lock();
            }
        } else {
            if (this->connectedToArrayPort) {
                this->unlock();
                status = setArrayInterrupt(0);
                this->lock();
            }
        }
    } else if (function == NDPluginDriverArrayAddr) {
        this->unlock();
        status = connectToArrayPort();
        this->lock();
    } else if (function == NDPluginDriverQueueSize) {
        newQueueSize_ = value;
     } else {
        /* If this parameter belongs to a base class call its method */
        if (function < FIRST_NDPLUGIN_PARAM) 
            status = asynNDArrayDriver::writeInt32(pasynUser, value);
    }
    
    /* Do callbacks so higher layers see any changes */
    callParamCallbacks(addr);
    
    if (status) 
        asynPrint(pasynUser, ASYN_TRACE_ERROR, 
              "%s:%s: function=%d, value=%d, connectedToArrayPort=%d\n", 
              driverName, functionName, function, value, this->connectedToArrayPort);
    else        
        asynPrint(pasynUser, ASYN_TRACEIO_DRIVER, 
              "%s:%s: function=%d, value=%d, connectedToArrayPort=%d\n", 
              driverName, functionName, function, value, connectedToArrayPort);
    return status;
}