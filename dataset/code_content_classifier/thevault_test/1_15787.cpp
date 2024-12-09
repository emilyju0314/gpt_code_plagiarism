int32_t AudioDeviceAndroidJni::PlayoutDelay(uint16_t& delayMS) const
{
    delayMS = _delayPlayout;

    return 0;
}