static bool 
SetSocketOptions(jdwpTransportEnv* env, hysocket_t sckt) 
{
    JavaVM *vm = ((internalEnv*)env->functions->reserved1)->jvm;
    PORT_ACCESS_FROM_JAVAVM(vm);

    BOOLEAN isOn = TRUE;

#ifndef ZOS
    if (hysock_setopt_bool(sckt, HY_SOL_SOCKET, HY_SO_REUSEADDR, &isOn) != 0){
        SetLastTranError(env, "setsockopt(SO_REUSEADDR) failed", GetLastErrorStatus(env));
        return false;
    }
    if (hysock_setopt_bool(sckt, HY_IPPROTO_TCP, HY_TCP_NODELAY,  &isOn) != 0) {
        SetLastTranError(env, "setsockopt(TCPNODELAY) failed", GetLastErrorStatus(env));
        return false;
    }
#endif

    return true;
}