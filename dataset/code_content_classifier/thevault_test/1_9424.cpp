std::string AndroidGetActivityName() {
  JNIEnv *env = AndroidGetJNIEnv();
  jobject activity = AndroidGetActivity();
  jclass activity_class = env->GetObjectClass(activity);
  jmethodID get_class_method =
      env->GetMethodID(activity_class, "getClass", "()Ljava/lang/Class;");
  // Get the class instance.
  jclass activity_class_object =
      static_cast<jclass>(env->CallObjectMethod(activity, get_class_method));
  jclass activity_class_object_class =
      env->GetObjectClass(activity_class_object);
  jmethodID get_name_method = env->GetMethodID(
      activity_class_object_class, "getName", "()Ljava/lang/String;");
  jstring class_name_object = static_cast<jstring>(
      env->CallObjectMethod(activity_class_object, get_name_method));
  const char *class_name = env->GetStringUTFChars(class_name_object, JNI_FALSE);
  std::string activity_name(class_name);
  env->ReleaseStringUTFChars(class_name_object, class_name);
  env->DeleteLocalRef(class_name_object);
  env->DeleteLocalRef(activity_class_object_class);
  env->DeleteLocalRef(activity_class_object);
  env->DeleteLocalRef(activity_class);
  env->DeleteLocalRef(activity);
  return activity_name;
}