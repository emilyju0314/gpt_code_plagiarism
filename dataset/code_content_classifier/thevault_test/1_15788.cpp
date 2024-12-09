int32_t AudioDeviceAndroidJni::RecordingDelay(
        uint16_t& delayMS) const
{
    delayMS = _delayRecording;

    return 0;
}