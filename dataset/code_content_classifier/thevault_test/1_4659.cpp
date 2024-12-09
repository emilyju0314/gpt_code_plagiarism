static jdwpTransportError
DecodeAddress(jdwpTransportEnv* env, const char *address, hysockaddr_t sa, bool isServer) 
{
    JavaVM *vm = ((internalEnv*)env->functions->reserved1)->jvm;
    PORT_ACCESS_FROM_JAVAVM(vm);
    const char * localhost = "127.0.0.1";
    const char * anyhost = "0.0.0.0";

    if ((address == 0) || (*address == 0)) {  //empty address
        hysock_sockaddr(sa,  isServer ? anyhost : localhost, 0);
        return JDWPTRANSPORT_ERROR_NONE;
    }

    char *finalAddress = (char*)(((internalEnv*)env->functions->reserved1)->alloc)((jint)strlen(address)+1);
    if (finalAddress == 0) {
        SetLastTranError(env, "out of memory", 0);
        return JDWPTRANSPORT_ERROR_OUT_OF_MEMORY;
    }
    memcpy(finalAddress, address, strlen(address)+1);

#ifdef ZOS
    __a2e_s(finalAddress);
#endif

#ifdef ZOS
// Ensure that the ':' is in EBCDIC on zOS platforms
#pragma convlit(suspend)
#endif
    const char* colon = strchr(finalAddress, ':');
#ifdef ZOS
#pragma convlit(resume)
#endif
    if (colon == 0) {  //address is like "port"
        hysock_sockaddr(sa,  isServer ? anyhost : localhost,  hysock_htons((U_16)atoi(finalAddress)));
    } else { //address is like "host:port"
        char *hostName = (char*)(((internalEnv*)env->functions->reserved1)
            ->alloc)((jint)(colon - finalAddress + 1));
        if (hostName == 0) {
            SetLastTranError(env, "out of memory", 0);
            (((internalEnv*)env->functions->reserved1)->free)(finalAddress);
            return JDWPTRANSPORT_ERROR_OUT_OF_MEMORY;
        }
        memcpy(hostName, address, colon - finalAddress); // Use address here, not finalAddress, as we want to keep the string ASCII on zOS
        hostName[colon - finalAddress] = '\0';
        int ret = hysock_sockaddr(sa,  hostName, hysock_htons((U_16)atoi(colon + 1)));
        if (ret != 0){
                SetLastTranError(env, "unable to resolve host name", 0);
                (((internalEnv*)env->functions->reserved1)->free)(hostName);
                (((internalEnv*)env->functions->reserved1)->free)(finalAddress);
                return JDWPTRANSPORT_ERROR_IO_ERROR;
        }
        (((internalEnv*)env->functions->reserved1)->free)(hostName);
    } //if
    (((internalEnv*)env->functions->reserved1)->free)(finalAddress);

    return JDWPTRANSPORT_ERROR_NONE;
}