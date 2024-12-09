static void 
SetLastTranError(jdwpTransportEnv* env, const char* messagePtr, int errorStatus)
{
    internalEnv* ienv = (internalEnv*)env->functions->reserved1;
    if (ienv->lastError != 0) {
        ienv->lastError->insertError(messagePtr, errorStatus);
    } else {
        ienv->lastError = new(ienv->alloc, ienv->free) LastTransportError(ienv->jvm, messagePtr, errorStatus, ienv->alloc, ienv->free);
    }
    return;
}