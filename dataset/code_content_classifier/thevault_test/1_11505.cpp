std::thread directForwarding(CSSHChannel &forwardingChannel, const std::string &remoteHost, int remotePort, const std::string &localHost, int localPort, IOContext &ioContext)
    {
        forwardingChannel.openForward(remoteHost, remotePort, localHost, localPort);
        std::thread channelReadThread{readChannelThread, std::ref(forwardingChannel), std::ref(ioContext)};
        return (channelReadThread);
    }