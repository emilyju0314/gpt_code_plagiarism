void NDPluginOverlay::processCallbacks(NDArray *pArray)
{
    /* This function draws overlays
     * It is called with the mutex already locked.  It unlocks it during long calculations when private
     * structures don't need to be protected.
     */

    int use;
    int itemp;
    int overlay;
    NDArray *pOutput;
    //static const char* functionName = "processCallbacks";

    /* Call the base class method */
    NDPluginDriver::processCallbacks(pArray);

    /* We always keep the last array so read() can use it.
     * Release previous one. */
    if (this->pArrays[0]) {
        this->pArrays[0]->release();
    }
    /* Copy the input array so we can modify it. */
    this->pArrays[0] = this->pNDArrayPool->copy(pArray, NULL, 1);
    pOutput = this->pArrays[0];
    
    /* Get information about the array needed later */
    pOutput->getInfo(&this->arrayInfo);
    setIntegerParam(NDPluginOverlayMaxSizeX, (int)arrayInfo.xSize);
    setIntegerParam(NDPluginOverlayMaxSizeY, (int)arrayInfo.ySize);
   
    /* Loop over the overlays in this driver */
    for (overlay=0; overlay<this->maxOverlays; overlay++) {
        pOverlay = &this->pOverlays[overlay];
        getIntegerParam(overlay, NDPluginOverlayUse, &use);
        asynPrint(pasynUserSelf, ASYN_TRACEIO_DRIVER,
            "NDPluginOverlay::processCallbacks, overlay=%d, use=%d\n",
            overlay, use);
        if (!use) continue;
        /* Need to fetch all of these parameters while we still have the mutex */
        getIntegerParam(overlay, NDPluginOverlayPositionX,  &itemp); pOverlay->PositionX = itemp;
        pOverlay->PositionX = MAX(pOverlay->PositionX, 0);
        pOverlay->PositionX = MIN(pOverlay->PositionX, this->arrayInfo.xSize-1);
        getIntegerParam(overlay, NDPluginOverlayPositionY,  &itemp); pOverlay->PositionY = itemp;
        pOverlay->PositionY = MAX(pOverlay->PositionY, 0);
        pOverlay->PositionY = MIN(pOverlay->PositionY, this->arrayInfo.ySize-1);
        getIntegerParam(overlay, NDPluginOverlaySizeX,      &itemp); pOverlay->SizeX = itemp;
        getIntegerParam(overlay, NDPluginOverlaySizeY,      &itemp); pOverlay->SizeY = itemp;
        getIntegerParam(overlay, NDPluginOverlayWidthX,     &itemp); pOverlay->WidthX = itemp;
        getIntegerParam(overlay, NDPluginOverlayWidthY,     &itemp); pOverlay->WidthY = itemp;
        getIntegerParam(overlay, NDPluginOverlayShape,      &itemp); pOverlay->shape = (NDOverlayShape_t)itemp;
        getIntegerParam(overlay, NDPluginOverlayDrawMode,   &itemp); pOverlay->drawMode = (NDOverlayDrawMode_t)itemp;
        getIntegerParam(overlay, NDPluginOverlayRed,        &pOverlay->red);
        getIntegerParam(overlay, NDPluginOverlayGreen,      &pOverlay->green);
        getIntegerParam(overlay, NDPluginOverlayBlue,       &pOverlay->blue);
        getStringParam( overlay, NDPluginOverlayTimeStampFormat, sizeof(pOverlay->TimeStampFormat), pOverlay->TimeStampFormat);
        getIntegerParam(overlay, NDPluginOverlayFont,       &pOverlay->Font);
        getStringParam( overlay, NDPluginOverlayDisplayText, sizeof(pOverlay->DisplayText), pOverlay->DisplayText);

        pOverlay->DisplayText[sizeof(pOverlay->DisplayText)-1] = 0;

        /* This function is called with the lock taken, and it must be set when we exit.
         * The following code can be exected without the mutex because we are not accessing memory
         * that other threads can access. */
        this->unlock();
        this->doOverlay(pOutput, pOverlay);
        this->lock();
    }
    /* Get the attributes for this driver */
    this->getAttributes(this->pArrays[0]->pAttributeList);
    /* Call any clients who have registered for NDArray callbacks */
    this->unlock();
    doCallbacksGenericPointer(this->pArrays[0], NDArrayData, 0);
    this->lock();
    callParamCallbacks();
}