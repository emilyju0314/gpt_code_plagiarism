static bool 
SetSocketBlockingMode(jdwpTransportEnv* env, hysocket_t sckt, bool isBlocked)
{
    JavaVM *vm = ((internalEnv*)env->functions->reserved1)->jvm;
    PORT_ACCESS_FROM_JAVAVM(vm);

    jint ret = hysock_set_nonblocking(sckt, isBlocked ? FALSE : TRUE);
    if (ret != 0){
	SetLastTranError(env, "socket error", GetLastErrorStatus(env));
        return false;
    }
    return true;

}