JavaThreadInfo* 
ThreadManager::AddJavaThread(JNIEnv *jni, jthread thread)
   
{
    JDWP_TRACE_ENTRY(LOG_RELEASE, (LOG_FUNC_FL, "AddJavaThread(%p,%p)", jni, thread));

    MonitorAutoLock lock(m_javathrdmgrMonitor JDWP_FILE_LINE);

    jint place = -1,found = -1;
    JavaThreadInfoList::iterator result = m_javaThreadInfoList.begin();
    for (;result.hasNext();) {
        JavaThreadInfo* element = result.getNext();
        if (element == NULL) {
            // save pointer to empty slot
            place = result.getIndex();
        } else if (jni->IsSameObject((element)->m_thread, thread) == JNI_TRUE) {
            found = result.getIndex();
            // thread found
            break;
        }
    }

    // not found
    if  (found == -1)
    {
        JavaThreadInfo *thrdinf = new JavaThreadInfo(jni, thread);

#ifndef NDEBUG
        // save thread name for debugging purpose
        if (JDWP_TRACE_ENABLED(LOG_KIND_THREAD)) {
            jvmtiError err;
            jvmtiThreadInfo info;

            JVMTI_TRACE(LOG_DEBUG, err, GetJvmtiEnv()->GetThreadInfo(thread, &info));
            JvmtiAutoFree jafInfoName(info.name);
            if (err == JVMTI_ERROR_NONE) {
                JDWP_TRACE(LOG_RELEASE, (LOG_THREAD_FL, "AddJavaThread: add thread=%p, name=%s", thread, JDWP_CHECK_NULL(info.name)));
            }
        }        
#endif // NDEBUG        

        if (place !=-1) {
            m_javaThreadInfoList.insert(place,thrdinf);
        } else {
            m_javaThreadInfoList.push_back(thrdinf);
        }

        return thrdinf;
    }

    return result.getCurrent();
}