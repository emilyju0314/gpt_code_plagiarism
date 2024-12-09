ThreadInfo(JNIEnv *jni, jthread thrd, bool isAgentThrd = false, bool isOnEvent = false)
        {
            m_thread = jni->NewGlobalRef(thrd);
            if (m_thread == 0) {
                JDWP_TRACE(LOG_RELEASE, (LOG_ERROR_FL, "Unable to allocate new global ref for ThreadInfo"));
            }
            m_isAgentThread = isAgentThrd;
            m_isOnEvent = isOnEvent;
            m_suspendCount = 0;
            m_threadName = 0;
            m_isAlive = 1;
        }