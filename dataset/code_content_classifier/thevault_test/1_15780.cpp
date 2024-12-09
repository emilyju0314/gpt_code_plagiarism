int32_t AudioDeviceModuleImpl::TimeUntilNextProcess()
{
    uint32_t now = AudioDeviceUtility::GetTimeInMS();
    int32_t deltaProcess = kAdmMaxIdleTimeProcess - (now - _lastProcessTime);
    return (deltaProcess);
}