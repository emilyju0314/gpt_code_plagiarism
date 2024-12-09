void SendKeypressEventToAndroid(int android_key_code) {
  jobject activity = AndroidGetActivity(true);
  if (!activity)
    return;
  JNIEnv *env = AndroidGetJNIEnv();
  jclass fpl_class = env->GetObjectClass(activity);
  jmethodID method_id =
      env->GetMethodID(fpl_class, "SendKeypressEventToAndroid", "(I)V");
  env->CallVoidMethod(activity, method_id, android_key_code);
  env->DeleteLocalRef(fpl_class);
  env->DeleteLocalRef(activity);
}