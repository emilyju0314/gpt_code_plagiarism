static long 
GetTickCount(jdwpTransportEnv* env)
{
    internalEnv* ienv = (internalEnv*)env->functions->reserved1;
    PORT_ACCESS_FROM_JAVAVM(ienv->jvm);
    return (long)hytime_current_time_millis();
}