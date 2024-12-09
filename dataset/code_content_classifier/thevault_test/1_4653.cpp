static void 
SetLastTranErrorMessagePrefix(jdwpTransportEnv* env, const char* messagePrefix)
{
    internalEnv* ienv = (internalEnv*)env->functions->reserved1;
    if (ienv->lastError != 0) {
        ienv->lastError->addErrorMessagePrefix(messagePrefix);
    }
    return;
}