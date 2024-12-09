static void debugLog(int logLevel, const char* message)
{
	JNIEnv* env = JNIScope::getEnv();
	if (env == NULL) {
		LOGE(LCAT, "Failed to get JNI environment.");
		return;
	}

	jstring javaMessage = env->NewStringUTF(message);
	env->CallStaticVoidMethod(JNIUtil::krollLoggingClass,
	                          JNIUtil::krollLoggingLogWithDefaultLoggerMethod,
	                          logLevel,
	                          javaMessage);
	env->DeleteLocalRef(javaMessage);
}