void FindThreadInfo(JNIEnv *jni, ThreadInfoList *thrdInfoList, jthread thread,
        ThreadInfoList::iterator &result)
    {
        for (; result.hasNext();) {
            ThreadInfo* element= result.getNext();
            if (element != 0 && 
                    jni->IsSameObject((element)->m_thread, thread) == JNI_TRUE){
		    // TODO revert this JDWP_TRACE(LOG_RELEASE, (LOG_THREAD_FL, "FindThreadInfo : agent thread=%p, name=%s, oldCount=%d, isOnEvent=%d", (element)->m_thread, JDWP_CHECK_NULL(((element)->m_thread)->m_threadName), ((element)->m_thread)->m_suspendCount, ((element)->m_thread)->m_isOnEvent));
                break;
            }
        }
    }