int32_t AudioDeviceIPhone::SetLoudspeakerStatus(bool enable) {
    WEBRTC_TRACE(kTraceInfo, kTraceAudioDevice, _id,
                 "AudioDeviceIPhone::SetLoudspeakerStatus(enable=%d)", enable);

    UInt32 doChangeDefaultRoute = enable ? 1 : 0;
    OSStatus err = AudioSessionSetProperty(
        kAudioSessionProperty_OverrideCategoryDefaultToSpeaker,
        sizeof(doChangeDefaultRoute), &doChangeDefaultRoute);

    if (err != noErr) {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
            "Error changing default output route " \
            "(only available on iOS 3.1 or later)");
        return -1;
    }

    return 0;
}