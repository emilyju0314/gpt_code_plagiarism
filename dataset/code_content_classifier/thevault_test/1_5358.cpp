bool ts::UDPSocket::receive(void* data,
                            size_t max_size,
                            size_t& ret_size,
                            SocketAddress& sender,
                            SocketAddress& destination,
                            const AbortInterface* abort,
                            Report& report)
{
    // Loop on unsollicited interrupts
    for (;;) {

        // Wait for a message.
        const SocketErrorCode err = receiveOne(data, max_size, ret_size, sender, destination, report);

        if (abort != nullptr && abort->aborting()) {
            // Aborting, no error message.
            return false;
        }
        else if (err == SYS_SUCCESS) {
            // Sometimes, we get "successful" empty message coming from nowhere. Ignore them.
            if (ret_size > 0 || sender.hasAddress()) {
                return true;
            }
        }
        else if (abort != nullptr && abort->aborting()) {
            // User-interrupt, end of processing but no error message
            return false;
        }
#if !defined(TS_WINDOWS)
        else if (err == EINTR) {
            // Got a signal, not a user interrupt, will ignore it
            report.debug(u"signal, not user interrupt");
        }
#endif
        else {
            // Abort on non-interrupt errors.
            report.error(u"error receiving from UDP socket: %s", {SocketErrorCodeMessage(err)});
            return false;
        }
    }