static jdwpTransportError
SendData(jdwpTransportEnv* env, hysocket_t sckt, const char* data, int dataLength, jlong deadline = 0)
{
    long left = dataLength;
    long off = 0;
    int ret;

    JavaVM *vm = ((internalEnv*)env->functions->reserved1)->jvm;
    PORT_ACCESS_FROM_JAVAVM(vm);

    // Check if block
    while (left > 0){
#ifndef ZOS	    
        jdwpTransportError err = SelectSend(env, sckt, deadline);
        if (err != JDWPTRANSPORT_ERROR_NONE) {
            return err;
        }
#endif
#ifdef ZOS
	if (!SetSocketBlockingMode(env, sckt, true)) {
            return JDWPTRANSPORT_ERROR_IO_ERROR;
        }
#endif	
	ret = hysock_write (sckt, (U_8 *)data+off, left, HYSOCK_NOFLAGS);
#ifdef ZOS
	if (!SetSocketBlockingMode(env, sckt, false)) {
            return JDWPTRANSPORT_ERROR_IO_ERROR;
        }
#endif	
	if (ret < 0){
                SetLastTranError(env, "socket error", ret);
                return JDWPTRANSPORT_ERROR_IO_ERROR; 
	}
	left -= ret;
	off += ret;
    }    
    return JDWPTRANSPORT_ERROR_NONE;
}