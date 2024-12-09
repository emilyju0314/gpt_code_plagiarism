bool DataDistributeBase::GetBatchSafe(XList * args)
{
    bool r;

    MUTEX_LOCK(loadMutex);
    r = GetBatch(args);
    MUTEX_UNLOCK(loadMutex);

    return r;
}