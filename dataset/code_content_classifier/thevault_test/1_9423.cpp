bool IsTvDevice() {
#ifdef __ANDROID__
  JNIEnv *env = AndroidGetJNIEnv();
  jobject activity = AndroidGetActivity();
  jclass fpl_class = env->GetObjectClass(activity);
  jmethodID is_tv_device = env->GetMethodID(fpl_class, "IsTvDevice", "()Z");
  jboolean result = env->CallBooleanMethod(activity, is_tv_device);
  env->DeleteLocalRef(fpl_class);
  env->DeleteLocalRef(activity);
  return result;
#else
  return false;
#endif  // __ANDROID
}