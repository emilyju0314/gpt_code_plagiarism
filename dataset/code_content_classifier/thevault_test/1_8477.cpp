NDPluginOverlay::NDPluginOverlay(const char *portName, int queueSize, int blockingCallbacks,
                         const char *NDArrayPort, int NDArrayAddr, int maxOverlays,
                         int maxBuffers, size_t maxMemory,
                         int priority, int stackSize)
    /* Invoke the base class constructor */
    : NDPluginDriver(portName, queueSize, blockingCallbacks,
                   NDArrayPort, NDArrayAddr, maxOverlays, NUM_NDPLUGIN_OVERLAY_PARAMS, maxBuffers, maxMemory,
                   asynGenericPointerMask,
                   asynGenericPointerMask,
                   ASYN_MULTIDEVICE, 1, priority, stackSize)
{
    static const char *functionName = "NDPluginOverlay";


    this->maxOverlays = maxOverlays;
    this->pOverlays = (NDOverlay_t *)callocMustSucceed(maxOverlays, sizeof(*this->pOverlays), functionName);

    createParam(NDPluginOverlayMaxSizeXString,      asynParamInt32, &NDPluginOverlayMaxSizeX);
    createParam(NDPluginOverlayMaxSizeYString,      asynParamInt32, &NDPluginOverlayMaxSizeY);
    createParam(NDPluginOverlayNameString,          asynParamOctet, &NDPluginOverlayName);
    createParam(NDPluginOverlayUseString,           asynParamInt32, &NDPluginOverlayUse);
    createParam(NDPluginOverlayPositionXString,     asynParamInt32, &NDPluginOverlayPositionX);
    createParam(NDPluginOverlayPositionYString,     asynParamInt32, &NDPluginOverlayPositionY);
    createParam(NDPluginOverlaySizeXString,         asynParamInt32, &NDPluginOverlaySizeX);
    createParam(NDPluginOverlaySizeYString,         asynParamInt32, &NDPluginOverlaySizeY);
    createParam(NDPluginOverlayWidthXString,        asynParamInt32, &NDPluginOverlayWidthX);
    createParam(NDPluginOverlayWidthYString,        asynParamInt32, &NDPluginOverlayWidthY);
    createParam(NDPluginOverlayShapeString,         asynParamInt32, &NDPluginOverlayShape);
    createParam(NDPluginOverlayDrawModeString,      asynParamInt32, &NDPluginOverlayDrawMode);
    createParam(NDPluginOverlayRedString,           asynParamInt32, &NDPluginOverlayRed);
    createParam(NDPluginOverlayGreenString,         asynParamInt32, &NDPluginOverlayGreen);
    createParam(NDPluginOverlayBlueString,          asynParamInt32, &NDPluginOverlayBlue);
    createParam(NDPluginOverlayTimeStampFormatString, asynParamOctet, &NDPluginOverlayTimeStampFormat);
    createParam(NDPluginOverlayFontString,          asynParamInt32, &NDPluginOverlayFont);
    createParam(NDPluginOverlayDisplayTextString,   asynParamOctet, &NDPluginOverlayDisplayText);      

    /* Set the plugin type string */
    setStringParam(NDPluginDriverPluginType, "NDPluginOverlay");

    // Enable ArrayCallbacks.  
    // This plugin currently ignores this setting and always does callbacks, so make the setting reflect the behavior
    setIntegerParam(NDArrayCallbacks, 1);

    /* Try to connect to the array port */
    connectToArrayPort();
}