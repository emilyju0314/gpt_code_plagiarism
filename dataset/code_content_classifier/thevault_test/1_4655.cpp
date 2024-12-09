static jdwpTransportError 
SelectRead(jdwpTransportEnv* env, hysocket_t sckt, jlong deadline = 0) {
    internalEnv* ienv = (internalEnv*)env->functions->reserved1;
    PORT_ACCESS_FROM_JAVAVM(ienv->jvm);

    if (deadline < 0)
        return JDWPTRANSPORT_ERROR_NONE;

    // default to 5s but don't allow anything less than 1s
    deadline =
      deadline == 0 ? select_timeout : (deadline < 1000 ? 1000 : deadline);
    jint ret = hysock_select_read(sckt, (I_32) deadline / 1000 , (I_32) deadline % 1000, FALSE);
    if (ret == 1){
        return JDWPTRANSPORT_ERROR_NONE; //timeout is not occurred
    }
    if (ret != HYPORT_ERROR_SOCKET_TIMEOUT){
        SetLastTranError(env, "socket error", ret);

        return JDWPTRANSPORT_ERROR_IO_ERROR;
    }
    SetLastTranError(env, "timeout occurred", 0);
    return JDWPTRANSPORT_ERROR_TIMEOUT; //timeout occurred
}