static inline void
DeleteCriticalSections(jdwpTransportEnv* env)
{
    internalEnv* ienv = (internalEnv*)env->functions->reserved1;
    JavaVM *vm = ienv->jvm;
#ifdef HY_NO_THR
    THREAD_ACCESS_FROM_JAVAVM(vm);
#endif /* HY_NO_THR */

    hythread_attach(NULL);
    hythread_monitor_destroy(ienv->readLock);
    hythread_monitor_destroy(ienv->sendLock);
}