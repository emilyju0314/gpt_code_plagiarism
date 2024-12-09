void NDPluginDriver::processTask(void)
{
    /* This thread processes a new array when it arrives */
    int queueSize, queueFree;
    static const char *functionName = "processTask";

    /* Loop forever */
    NDArray *pArray;

    this->lock();
    this->pThreadStartedEvent->signal();
    while (1) {
        /* If the queue size has been changed in the writeInt32 method then create a new one */
        if (newQueueSize_ > 0) {
            /* Need to empty the queue and decrease reference count on arrays that were in the queue */
            while (epicsMessageQueueTryReceive(this->msgQId, &pArray, sizeof(&pArray)) != -1) {
                pArray->release();
            }
            epicsMessageQueueDestroy(this->msgQId);
            this->msgQId = epicsMessageQueueCreate(newQueueSize_, sizeof(NDArray*));
            if (!this->msgQId) {
                asynPrint(pasynUserSelf, ASYN_TRACE_ERROR, 
                          "%s::%s epicsMessageQueueCreate failure\n", driverName, functionName);
            }
            newQueueSize_ = 0;
        }

        /* Wait for an array to arrive from the queue. Release the lock while  waiting. */    
        this->unlock();
        epicsMessageQueueReceive(this->msgQId, &pArray, sizeof(&pArray));
        if (pArray == NULL || pArray->pData == NULL) {
          return; // shutdown thread if special NULL pData received
        }
        
        /* Take the lock.  The function we are calling must release the lock
         * during time-consuming operations when it does not need it. */
        this->lock();
        getIntegerParam(NDPluginDriverQueueSize, &queueSize);
        queueFree = queueSize - epicsMessageQueuePending(this->msgQId);
        setIntegerParam(NDPluginDriverQueueFree, queueFree);

        /* Call the function that does the business of this callback */
        processCallbacks(pArray); 
        
        /* We are done with this array buffer */
        pArray->release();
    }
}