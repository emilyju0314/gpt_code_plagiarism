asynStatus NDPluginDriver::setArrayInterrupt(int enableCallbacks)
{
    asynStatus status = asynSuccess;
    static const char *functionName = "setArrayInterrupt";
    
    if (enableCallbacks && !this->asynGenericPointerInterruptPvt) {
        status = this->pasynGenericPointer->registerInterruptUser(
                    this->asynGenericPointerPvt, this->pasynUserGenericPointer,
                    ::driverCallback, this, &this->asynGenericPointerInterruptPvt);
        if (status != asynSuccess) {
            asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
                "%s::%s ERROR: Can't register for interrupt callbacks on detector port: %s\n",
                driverName, functionName, this->pasynUserGenericPointer->errorMessage);
            return(status);
        }
    } 
    if (!enableCallbacks && this->asynGenericPointerInterruptPvt) {
        if (this->asynGenericPointerInterruptPvt) {
            status = this->pasynGenericPointer->cancelInterruptUser(this->asynGenericPointerPvt, 
                            this->pasynUserGenericPointer, this->asynGenericPointerInterruptPvt);
            this->asynGenericPointerInterruptPvt = NULL;
            if (status != asynSuccess) {
                asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
                    "%s::%s ERROR: Can't unregister for interrupt callbacks on detector port: %s\n",
                    driverName, functionName, this->pasynUserGenericPointer->errorMessage);
                return(status);
            }
        }
    }
    return(asynSuccess);
}