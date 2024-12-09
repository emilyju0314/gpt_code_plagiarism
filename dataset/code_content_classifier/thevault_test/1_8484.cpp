pvaDriver::pvaDriver (const char *portName, const char *pvName,
        int maxBuffers, size_t maxMemory, int priority, int stackSize)

    : ADDriver(portName, 1, NUM_PVA_DRIVER_PARAMS, maxBuffers, maxMemory, 0, 0, ASYN_CANBLOCK, 1,
            priority, stackSize),
      m_pvName(pvName), m_request(DEFAULT_REQUEST),
      m_priority(ChannelProvider::PRIORITY_DEFAULT),
      m_channel(),
      m_thisPtr(tr1::shared_ptr<pvaDriver>(this))
{
    int status = asynSuccess;
    const char *functionName = "pvaDriver";

    lock();
    createParam(PVAOverrunCounterString,     asynParamInt32, &PVAOverrunCounter);
    createParam(PVAPvNameString,             asynParamOctet, &PVAPvName);
    createParam(PVAPvConnectionStatusString, asynParamInt32, &PVAPvConnectionStatus);

    /* Set some default values for parameters */
    status =  setStringParam (ADManufacturer, "PVAccess driver");
    status |= setStringParam (ADModel, "Basic PVAccess driver");
    status |= setIntegerParam(ADMaxSizeX, 0);
    status |= setIntegerParam(ADMaxSizeY, 0);
    status |= setIntegerParam(ADMinX, 0);
    status |= setIntegerParam(ADMinY, 0);
    status |= setIntegerParam(ADBinX, 1);
    status |= setIntegerParam(ADBinY, 1);
    status |= setIntegerParam(ADReverseX, 0);
    status |= setIntegerParam(ADReverseY, 0);
    status |= setIntegerParam(ADSizeX, 0);
    status |= setIntegerParam(ADSizeY, 0);
    status |= setIntegerParam(NDArraySizeX, 0);
    status |= setIntegerParam(NDArraySizeY, 0);
    status |= setIntegerParam(NDArraySize, 0);
    status |= setIntegerParam(NDDataType, 0);
    status |= setIntegerParam(PVAOverrunCounter, 0);
    status |= setStringParam (PVAPvName, pvName);
    status |= setIntegerParam(PVAPvConnectionStatus, 0);

    if(status)
        asynPrint(pasynUserSelf, ASYN_TRACE_ERROR,
                "%s::%s unable to set driver parameters\n",
                driverName, functionName);

    try
    {
        ClientFactory::start();
        m_provider = getChannelProviderRegistry()->getProvider("pva");
        m_pvRequest = CreateRequest::create()->createRequest(m_request);
        connectPv();
    }
    catch (exception &ex)
    {
        asynPrint(pasynUserSelf, ASYN_TRACE_ERROR,
                "%s::%s exception initializing monitor: %s\n",
                driverName, functionName, ex.what());
    }
    unlock();
}