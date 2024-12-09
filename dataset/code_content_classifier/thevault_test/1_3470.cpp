CameraAdapter::AdapterState BaseCameraAdapter::getState()
{
    status_t ret = NO_ERROR;

    LOG_FUNCTION_NAME;

    android::AutoMutex lock(mLock);

    LOG_FUNCTION_NAME_EXIT;

    return mAdapterState;
}