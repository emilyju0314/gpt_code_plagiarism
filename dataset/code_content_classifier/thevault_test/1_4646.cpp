static inline void
InitializeCriticalSections(jdwpTransportEnv* env)
{
    internalEnv* ienv = (internalEnv*)env->functions->reserved1;
    JavaVM *vm = ienv->jvm;
#ifdef HY_NO_THR
    THREAD_ACCESS_FROM_JAVAVM(vm);
#endif /* HY_NO_THR */
    hythread_attach(NULL);

    UDATA flags = 0;
    if (hythread_monitor_init(&(ienv->readLock), 1) != 0) {
        printf("initial error\n");
    }

    if (hythread_monitor_init(&(ienv->sendLock), 1) != 0) {
        printf("initial error\n");
    }
    
}