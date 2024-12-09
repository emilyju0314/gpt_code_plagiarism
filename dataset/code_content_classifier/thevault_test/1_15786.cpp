int32_t AudioDeviceAndroidJni::SetStereoRecording(bool enable)
{

    if (enable)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "  Enabling not available");
        return -1;
    }

    return 0;
}