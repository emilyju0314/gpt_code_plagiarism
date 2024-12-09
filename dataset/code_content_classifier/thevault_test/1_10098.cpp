void LoadClasses(JNIEnv* jni) {
  for (auto& c : loaded_classes) {
    jclass localRef = FindClass(jni, c.name);
    CHECK_EXCEPTION(jni) << "Error during FindClass: " << c.name;
    RTC_CHECK(localRef) << c.name;
    jclass globalRef = reinterpret_cast<jclass>(jni->NewGlobalRef(localRef));
    CHECK_EXCEPTION(jni) << "Error during NewGlobalRef: " << c.name;
    RTC_CHECK(globalRef) << c.name;
    c.clazz = globalRef;
  }
}