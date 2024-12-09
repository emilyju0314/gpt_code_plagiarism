static jdwpTransportError 
SelectSend(jdwpTransportEnv* env, hysocket_t sckt, jlong deadline = 0) {
    JavaVM *vm = ((internalEnv*)env->functions->reserved1)->jvm;
    PORT_ACCESS_FROM_JAVAVM(vm);

    hyfdset_struct hyfdSet;
    deadline = deadline == 0 ? 20000 : deadline;
    
    I_32 secTime = (long)(deadline / 1000);
    I_32 uTime = (long)(deadline % 1000);

    hytimeval_struct timeval;

    hysock_fdset_zero(&hyfdSet);
    hysock_fdset_set(sckt,&hyfdSet);

    int ret = hysock_timeval_init(secTime,uTime,&timeval);

    ret =  hysock_select(hysock_fdset_size(sckt),NULL,&hyfdSet,NULL,&timeval);

    if (ret > 0){
        return JDWPTRANSPORT_ERROR_NONE; //timeout has not occurred
    }
    if (ret != HYPORT_ERROR_SOCKET_TIMEOUT){
    	 SetLastTranError(env, "socket error", ret);
         return JDWPTRANSPORT_ERROR_IO_ERROR;
    }
    SetLastTranError(env, "timeout occurred", 0);
    return JDWPTRANSPORT_ERROR_TIMEOUT; //timeout occurred
}