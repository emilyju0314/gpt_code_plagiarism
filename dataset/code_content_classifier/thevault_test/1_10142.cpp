int64_t AudioDeviceModuleImpl::TimeUntilNextProcess()
{
    int64_t now = TickTime::MillisecondTimestamp();
    int64_t deltaProcess = kAdmMaxIdleTimeProcess - (now - _lastProcessTime);
    return deltaProcess;
}