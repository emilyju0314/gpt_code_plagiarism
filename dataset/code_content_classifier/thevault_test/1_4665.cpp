void FindJavaThreadInfo(JNIEnv *jni, JavaThreadInfoList *javathrdInfoList, jthread thread,
        JavaThreadInfoList::iterator &result)
    {
        for (; result.hasNext();) {
            JavaThreadInfo* element= result.getNext();
            if (element != 0 && 
                    jni->IsSameObject((element)->m_thread, thread) == JNI_TRUE){
                break;
            }
        }
    }