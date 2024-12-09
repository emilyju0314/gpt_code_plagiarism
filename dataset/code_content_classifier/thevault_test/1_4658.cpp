static jdwpTransportError
ReceiveData(jdwpTransportEnv* env, hysocket_t sckt, U_8 * buffer, int dataLength, jlong deadline = 0, int* readByte = 0)
{
    JavaVM *vm = ((internalEnv*)env->functions->reserved1)->jvm;
    PORT_ACCESS_FROM_JAVAVM(vm);

    long left = dataLength;
    long off = 0;
    int ret;

    if (readByte != 0) {
        *readByte = 0;
    }
    while (left > 0) {
        jdwpTransportError err = SelectRead(env, sckt, deadline);
        if (err != JDWPTRANSPORT_ERROR_NONE) {
            return err;
        }

	if (!SetSocketBlockingMode(env, sckt, true)) {
            return JDWPTRANSPORT_ERROR_IO_ERROR;
    }
 	ret = hysock_read(sckt, (U_8 *) (buffer + off), left, HYSOCK_NOFLAGS);
	if (!SetSocketBlockingMode(env, sckt, false)) {
            return JDWPTRANSPORT_ERROR_IO_ERROR;
    }

        if (ret < 0) {
            SetLastTranError(env, "data receiving failed", ret);
            return JDWPTRANSPORT_ERROR_IO_ERROR;
        }
        if (ret == 0) {
            SetLastTranError(env, "premature EOF", HYSOCK_NOFLAGS);
            return JDWPTRANSPORT_ERROR_IO_ERROR;
        }
        left -= ret;
        off += ret;
        if (readByte != 0) {
            *readByte = off;
        }
    } //while

    return JDWPTRANSPORT_ERROR_NONE;   
}