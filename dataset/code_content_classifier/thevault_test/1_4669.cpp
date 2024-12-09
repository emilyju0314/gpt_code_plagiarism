bool 
ThreadManager::HasStepped(JNIEnv *jni, jthread thread) {
    MonitorAutoLock lock(m_javathrdmgrMonitor JDWP_FILE_LINE);
    JavaThreadInfoList::iterator result = m_javaThreadInfoList.begin();
    FindJavaThreadInfo(jni, &m_javaThreadInfoList, thread, result);

    jvmtiThreadInfo info;
    jvmtiError err;
    JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->GetThreadInfo(thread, &info));
    JvmtiAutoFree jafInfoName(info.name);

    // If we have found a matching entry, return it's value
    if  (result.hasCurrent()) {
            return (result.getCurrent())->m_hasStepped;
    }

    return false;
}