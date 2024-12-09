int32_t AudioDeviceModuleImpl::AttachAudioBuffer()
{
    WEBRTC_TRACE(kTraceInfo, kTraceAudioDevice, _id, "%s", __FUNCTION__);

    _audioDeviceBuffer.SetId(_id);
    _ptrAudioDevice->AttachAudioBuffer(&_audioDeviceBuffer);
    return 0;
}