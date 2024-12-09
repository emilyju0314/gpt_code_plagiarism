static int
GetLastErrorStatus(jdwpTransportEnv* env)
{
    internalEnv* ienv = (internalEnv*)env->functions->reserved1;
    PORT_ACCESS_FROM_JAVAVM(ienv->jvm);
    return hyerror_last_error_number();
}