int32_t AudioDeviceAndroidJni::InitSampleRate()
{
    int samplingFreq = 44100;
    jint res = 0;

    // get the JNI env for this thread
    JNIEnv *env;
    bool isAttached = false;

    // get the JNI env for this thread
    if (_javaVM->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK)
    {
        // try to attach the thread and get the env
        // Attach this thread to JVM
        jint res = _javaVM->AttachCurrentThread(&env, NULL);
        if ((res < 0) || !env)
        {
            WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                         "%s: Could not attach thread to JVM (%d, %p)",
                         __FUNCTION__, res, env);
            return -1;
        }
        isAttached = true;
    }

    if (_samplingFreqIn > 0)
    {
        // read the configured sampling rate
        samplingFreq = 44100;
        if (_samplingFreqIn != 44)
        {
            samplingFreq = _samplingFreqIn * 1000;
        }
        WEBRTC_TRACE(kTraceStateInfo, kTraceAudioDevice, _id,
                     "  Trying configured recording sampling rate %d",
                     samplingFreq);
    }

    // get the method ID
    jmethodID initRecordingID = env->GetMethodID(_javaScClass, "InitRecording",
                                                 "(II)I");

    bool keepTrying = true;
    while (keepTrying)
    {
        // call java sc object method
        res = env->CallIntMethod(_javaScObj, initRecordingID, _recAudioSource,
                                 samplingFreq);
        if (res < 0)
        {
            switch (samplingFreq)
            {
                case 44100:
                    samplingFreq = 16000;
                    break;
                case 16000:
                    samplingFreq = 8000;
                    break;
                default: // error
                    WEBRTC_TRACE(kTraceError,
                                 kTraceAudioDevice, _id,
                                 "%s: InitRecording failed (%d)", __FUNCTION__,
                                 res);
                    return -1;
            }
        }
        else
        {
            keepTrying = false;
        }
    }

    // set the recording sample rate to use
    if (samplingFreq == 44100)
    {
        _samplingFreqIn = 44;
    }
    else
    {
        _samplingFreqIn = samplingFreq / 1000;
    }

    WEBRTC_TRACE(kTraceStateInfo, kTraceAudioDevice, _id,
                 "Recording sample rate set to (%d)", _samplingFreqIn);

    // get the method ID
    jmethodID stopRecordingID = env->GetMethodID(_javaScClass, "StopRecording",
                                                 "()I");

    // Call java sc object method
    res = env->CallIntMethod(_javaScObj, stopRecordingID);
    if (res < 0)
    {
        WEBRTC_TRACE(kTraceWarning, kTraceAudioDevice, _id,
                     "StopRecording failed (%d)", res);
    }

    // get the method ID
    jmethodID initPlaybackID = env->GetMethodID(_javaScClass, "InitPlayback",
                                                "(I)I");

    if (_samplingFreqOut > 0)
    {
        // read the configured sampling rate
        samplingFreq = 44100;
        if (_samplingFreqOut != 44)
        {
            samplingFreq = _samplingFreqOut * 1000;
        }
        WEBRTC_TRACE(kTraceStateInfo, kTraceAudioDevice, _id,
                     "  Trying configured playback sampling rate %d",
                     samplingFreq);
    }
    else
    {
        // set the preferred sampling frequency
        if (samplingFreq == 8000)
        {
            // try 16000
            samplingFreq = 16000;
        }
        // else use same as recording
    }

    keepTrying = true;
    while (keepTrying)
    {
        // call java sc object method
        res = env->CallIntMethod(_javaScObj, initPlaybackID, samplingFreq);
        if (res < 0)
        {
            switch (samplingFreq)
            {
                case 44100:
                    samplingFreq = 16000;
                    break;
                case 16000:
                    samplingFreq = 8000;
                    break;
                default: // error
                    WEBRTC_TRACE(kTraceError,
                                 kTraceAudioDevice, _id,
                                 "InitPlayback failed (%d)", res);
                    return -1;
            }
        }
        else
        {
            keepTrying = false;
        }
    }

    // Store max playout volume
    _maxSpeakerVolume = static_cast<uint32_t> (res);
    if (_maxSpeakerVolume < 1)
    {
        WEBRTC_TRACE(kTraceWarning, kTraceAudioDevice, _id,
                     "  Did not get valid max speaker volume value (%d)",
                     _maxSpeakerVolume);
    }

    // set the playback sample rate to use
    if (samplingFreq == 44100)
    {
        _samplingFreqOut = 44;
    }
    else
    {
        _samplingFreqOut = samplingFreq / 1000;
    }

    WEBRTC_TRACE(kTraceStateInfo, kTraceAudioDevice, _id,
                 "Playback sample rate set to (%d)", _samplingFreqOut);

    // get the method ID
    jmethodID stopPlaybackID = env->GetMethodID(_javaScClass, "StopPlayback",
                                                "()I");

    // Call java sc object method
    res = env->CallIntMethod(_javaScObj, stopPlaybackID);
    if (res < 0)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "StopPlayback failed (%d)", res);
    }

    // Detach this thread if it was attached
    if (isAttached)
    {
        if (_javaVM->DetachCurrentThread() < 0)
        {
            WEBRTC_TRACE(kTraceWarning, kTraceAudioDevice, _id,
                         "%s: Could not detach thread from JVM", __FUNCTION__);
        }
    }

    return 0;
}