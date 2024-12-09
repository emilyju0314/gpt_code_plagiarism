bool SupportsHeadMountedDisplay() {
#if FPLBASE_ANDROID_VR
  JNIEnv *env = AndroidGetJNIEnv();
  jobject activity = AndroidGetActivity();
  jclass fpl_class = env->GetObjectClass(activity);
  jmethodID supports_hmd =
      env->GetMethodID(fpl_class, "SupportsHeadMountedDisplay", "()Z");
  jboolean result = env->CallBooleanMethod(activity, supports_hmd);
  env->DeleteLocalRef(fpl_class);
  env->DeleteLocalRef(activity);
  return result;
#else
  return false;
#endif  // FPLBASE_ANDROID_VR
}