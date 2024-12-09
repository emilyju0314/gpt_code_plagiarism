void ThreadManager::RemoveJavaThread(JNIEnv *jni, jthread thread) {
    JDWP_TRACE_ENTRY(LOG_RELEASE, (LOG_FUNC_FL, "RemoveJavaThread(%p,%p)", jni, thread));

    MonitorAutoLock lock(m_javathrdmgrMonitor JDWP_FILE_LINE);

    JavaThreadInfoList::iterator result = m_javaThreadInfoList.begin();
    for (;result.hasNext();) {
        JavaThreadInfo* element = result.getNext();
        if (element != NULL && jni->IsSameObject((element)->m_thread, thread) == JNI_TRUE) {
            // thread found, remove from list and destroy
            m_javaThreadInfoList.remove(result.getIndex());
            (element)->Clean(jni);
    	    delete element;
    	    element = 0;
    	    JDWP_TRACE(LOG_RELEASE, (LOG_THREAD_FL, "RemoveJavaThread: add thread=%p", thread));
    	    break;
    	}
    }
}