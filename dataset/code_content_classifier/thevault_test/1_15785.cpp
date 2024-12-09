int32_t AudioDeviceAndroidJni::SetAndroidAudioDeviceObjects(
    void* javaVM,
    void* env,
    void* context) {
  __android_log_print(ANDROID_LOG_DEBUG, "WEBRTC", "JNI:%s", __FUNCTION__);

  // TODO(leozwang): Make this function thread-safe.
  globalJvm = reinterpret_cast<JavaVM*>(javaVM);

  if (env) {
    globalJNIEnv = reinterpret_cast<JNIEnv*>(env);
    // Get java class type (note path to class packet).
    jclass javaScClassLocal = globalJNIEnv->FindClass(
        "org/webrtc/voiceengine/WebRTCAudioDevice");
    if (!javaScClassLocal) {
      WEBRTC_TRACE(kTraceError, kTraceAudioDevice, -1,
                   "%s: could not find java class", __FUNCTION__);
      return -1; // exception thrown
    }

    // Create a global reference to the class (to tell JNI that we are
    // referencing it after this function has returned).
    globalScClass = reinterpret_cast<jclass> (
        globalJNIEnv->NewGlobalRef(javaScClassLocal));
    if (!globalScClass) {
      WEBRTC_TRACE(kTraceError, kTraceAudioDevice, -1,
                   "%s: could not create reference", __FUNCTION__);
      return -1;
    }

    globalContext = globalJNIEnv->NewGlobalRef(
        reinterpret_cast<jobject>(context));
    if (!globalContext) {
      WEBRTC_TRACE(kTraceError, kTraceAudioDevice, -1,
                   "%s: could not create context reference", __FUNCTION__);
      return -1;
    }

    // Delete local class ref, we only use the global ref
    globalJNIEnv->DeleteLocalRef(javaScClassLocal);
  }
  else { // User is resetting the env variable
    WEBRTC_TRACE(kTraceStateInfo, kTraceAudioDevice, -1,
                 "%s: env is NULL, assuming deinit", __FUNCTION__);

    if (!globalJNIEnv) {
      WEBRTC_TRACE(kTraceWarning, kTraceAudioDevice, -1,
                   "%s: saved env already NULL", __FUNCTION__);
      return 0;
    }

    globalJNIEnv->DeleteGlobalRef(globalScClass);
    globalScClass = reinterpret_cast<jclass>(NULL);

    globalJNIEnv->DeleteGlobalRef(globalContext);
    globalContext = reinterpret_cast<jobject>(NULL);

    globalJNIEnv = reinterpret_cast<JNIEnv*>(NULL);
  }

  return 0;
}