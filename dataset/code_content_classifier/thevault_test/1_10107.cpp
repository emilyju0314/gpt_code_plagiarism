int64_t VideoCaptureImpl::TimeUntilNextProcess()
{
    CriticalSectionScoped cs(&_callBackCs);
    const int64_t kProcessIntervalMs = 300;
    return kProcessIntervalMs -
        (TickTime::Now() - _lastProcessTime).Milliseconds();
}