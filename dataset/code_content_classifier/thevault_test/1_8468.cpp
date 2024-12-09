asynStatus NDPluginDriver::connectToArrayPort(void)
{
    asynStatus status;
    asynInterface *pasynInterface;
    int enableCallbacks;
    char arrayPort[20];
    int arrayAddr;
    static const char *functionName = "connectToArrayPort";

    getStringParam(NDPluginDriverArrayPort, sizeof(arrayPort), arrayPort);
    getIntegerParam(NDPluginDriverArrayAddr, &arrayAddr);
    getIntegerParam(NDPluginDriverEnableCallbacks, &enableCallbacks);

    /* If we are currently connected to an array port cancel interrupt request */    
    if (this->connectedToArrayPort) {
        status = setArrayInterrupt(0);
    }
    
    /* Disconnect the array port from our asynUser.  Ignore error if there is no device
     * currently connected. */
    pasynManager->disconnect(this->pasynUserGenericPointer);
    this->connectedToArrayPort = false;

    /* Connect to the array port driver */
    status = pasynManager->connectDevice(this->pasynUserGenericPointer, arrayPort, arrayAddr);
    if (status != asynSuccess) {
        asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
                  "%s::%s Error calling pasynManager->connectDevice to array port %s address %d, status=%d, error=%s\n",
                  driverName, functionName, arrayPort, arrayAddr, status, this->pasynUserGenericPointer->errorMessage);
        return (status);
    }

    /* Find the asynGenericPointer interface in that driver */
    pasynInterface = pasynManager->findInterface(this->pasynUserGenericPointer, asynGenericPointerType, 1);
    if (!pasynInterface) {
        asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
                  "%s::connectToPort ERROR: Can't find asynGenericPointer interface on array port %s address %d\n",
                  driverName, arrayPort, arrayAddr);
        return(asynError);
    }
    this->pasynGenericPointer = (asynGenericPointer *)pasynInterface->pinterface;
    this->asynGenericPointerPvt = pasynInterface->drvPvt;
    this->connectedToArrayPort = true;

    /* Enable or disable interrupt callbacks */
    status = setArrayInterrupt(enableCallbacks);

    return(status);
}