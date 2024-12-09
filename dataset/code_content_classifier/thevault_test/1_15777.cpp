int32_t AudioDeviceIPhone::ResetAudioDevice() {
    WEBRTC_TRACE(kTraceModuleCall, kTraceAudioDevice, _id, "%s", __FUNCTION__);

    CriticalSectionScoped lock(&_critSect);

    if (!_playIsInitialized && !_recIsInitialized) {
        WEBRTC_TRACE(kTraceInfo, kTraceAudioDevice, _id,
                     "  Playout or recording not initialized, doing nothing");
        return 0;  // Nothing to reset
    }

    // Store the states we have before stopping to restart below
    bool initPlay = _playIsInitialized;
    bool play = _playing;
    bool initRec = _recIsInitialized;
    bool rec = _recording;

    int res(0);

    // Stop playout and recording
    WEBRTC_TRACE(kTraceDebug, kTraceAudioDevice, _id,
                 "  Stopping playout and recording");
    res += StopPlayout();
    res += StopRecording();

    // Restart
    WEBRTC_TRACE(kTraceDebug, kTraceAudioDevice, _id,
                 "  Restarting playout and recording (%d, %d, %d, %d)",
                 initPlay, play, initRec, rec);
    if (initPlay) res += InitPlayout();
    if (initRec)  res += InitRecording();
    if (play)     res += StartPlayout();
    if (rec)      res += StartRecording();

    if (0 != res) {
        // Logging is done in init/start/stop calls above
        return -1;
    }

    return 0;
}