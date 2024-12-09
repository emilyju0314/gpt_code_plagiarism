void XModel::LockParamsForTraining()
{
    for (int i = 0; i < paramNum; i++) {
        params[i].trainFlag = PARAM_STATE_NOT_READY;
        MUTEX_LOCK(params[i].trainLock);

        /* where is UNLOCK? We will do this when the training (a step)
           is finsished. Then, WaitForUnlockedParams() can continue. In
           such a way, we implement a START-WAIT process in each run
           of training (a step) */
    }
}