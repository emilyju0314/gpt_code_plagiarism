int32_t AudioDeviceAndroidJni::InitJavaResources()
{
    // todo: Check if we already have created the java object
    _javaVM = globalJvm;
    _javaScClass = globalScClass;

    // use the jvm that has been set
    if (!_javaVM)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: Not a valid Java VM pointer", __FUNCTION__);
        return -1;
    }

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

    WEBRTC_TRACE(kTraceDebug, kTraceAudioDevice, _id,
                 "get method id");

    // get the method ID for the void(void) constructor
    jmethodID cid = env->GetMethodID(_javaScClass, "<init>", "()V");
    if (cid == NULL)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get constructor ID", __FUNCTION__);
        return -1; /* exception thrown */
    }

    WEBRTC_TRACE(kTraceDebug, kTraceAudioDevice, _id,
                 "construct object", __FUNCTION__);

    // construct the object
    jobject javaScObjLocal = env->NewObject(_javaScClass, cid);
    if (!javaScObjLocal)
    {
        WEBRTC_TRACE(kTraceWarning, kTraceAudioDevice, _id,
                     "%s: could not create Java sc object", __FUNCTION__);
        return -1;
    }

    // Create a reference to the object (to tell JNI that we are referencing it
    // after this function has returned).
    _javaScObj = env->NewGlobalRef(javaScObjLocal);
    if (!_javaScObj)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not create Java sc object reference",
                     __FUNCTION__);
        return -1;
    }

    // Delete local object ref, we only use the global ref.
    env->DeleteLocalRef(javaScObjLocal);

    //////////////////////
    // AUDIO MANAGEMENT

    // This is not mandatory functionality
    if (globalContext) {
      jfieldID context_id = env->GetFieldID(globalScClass,
                                            "_context",
                                            "Landroid/content/Context;");
      if (!context_id) {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get _context id", __FUNCTION__);
        return -1;
      }

      env->SetObjectField(_javaScObj, context_id, globalContext);
      jobject javaContext = env->GetObjectField(_javaScObj, context_id);
      if (!javaContext) {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not set or get _context", __FUNCTION__);
        return -1;
      }
    }
    else {
      WEBRTC_TRACE(kTraceWarning, kTraceAudioDevice, _id,
                   "%s: did not set Context - some functionality is not "
                   "supported",
                   __FUNCTION__);
    }

    /////////////
    // PLAYOUT

    // Get play buffer field ID.
    jfieldID fidPlayBuffer = env->GetFieldID(_javaScClass, "_playBuffer",
                                             "Ljava/nio/ByteBuffer;");
    if (!fidPlayBuffer)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get play buffer fid", __FUNCTION__);
        return -1;
    }

    // Get play buffer object.
    jobject javaPlayBufferLocal =
            env->GetObjectField(_javaScObj, fidPlayBuffer);
    if (!javaPlayBufferLocal)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get play buffer", __FUNCTION__);
        return -1;
    }

    // Create a global reference to the object (to tell JNI that we are
    // referencing it after this function has returned)
    // NOTE: we are referencing it only through the direct buffer (see below).
    _javaPlayBuffer = env->NewGlobalRef(javaPlayBufferLocal);
    if (!_javaPlayBuffer)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get play buffer reference", __FUNCTION__);
        return -1;
    }

    // Delete local object ref, we only use the global ref.
    env->DeleteLocalRef(javaPlayBufferLocal);

    // Get direct buffer.
    _javaDirectPlayBuffer = env->GetDirectBufferAddress(_javaPlayBuffer);
    if (!_javaDirectPlayBuffer)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get direct play buffer", __FUNCTION__);
        return -1;
    }

    // Get the play audio method ID.
    _javaMidPlayAudio = env->GetMethodID(_javaScClass, "PlayAudio", "(I)I");
    if (!_javaMidPlayAudio)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get play audio mid", __FUNCTION__);
        return -1;
    }

    //////////////
    // RECORDING

    // Get rec buffer field ID.
    jfieldID fidRecBuffer = env->GetFieldID(_javaScClass, "_recBuffer",
                                            "Ljava/nio/ByteBuffer;");
    if (!fidRecBuffer)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get rec buffer fid", __FUNCTION__);
        return -1;
    }

    // Get rec buffer object.
    jobject javaRecBufferLocal = env->GetObjectField(_javaScObj, fidRecBuffer);
    if (!javaRecBufferLocal)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get rec buffer", __FUNCTION__);
        return -1;
    }

    // Create a global reference to the object (to tell JNI that we are
    // referencing it after this function has returned)
    // NOTE: we are referencing it only through the direct buffer (see below).
    _javaRecBuffer = env->NewGlobalRef(javaRecBufferLocal);
    if (!_javaRecBuffer)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get rec buffer reference", __FUNCTION__);
        return -1;
    }

    // Delete local object ref, we only use the global ref.
    env->DeleteLocalRef(javaRecBufferLocal);

    // Get direct buffer.
    _javaDirectRecBuffer = env->GetDirectBufferAddress(_javaRecBuffer);
    if (!_javaDirectRecBuffer)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get direct rec buffer", __FUNCTION__);
        return -1;
    }

    // Get the rec audio method ID.
    _javaMidRecAudio = env->GetMethodID(_javaScClass, "RecordAudio", "(I)I");
    if (!_javaMidRecAudio)
    {
        WEBRTC_TRACE(kTraceError, kTraceAudioDevice, _id,
                     "%s: could not get rec audio mid", __FUNCTION__);
        return -1;
    }

    // Detach this thread if it was attached.
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