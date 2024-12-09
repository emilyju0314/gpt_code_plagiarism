void PluginProcessProxy::createWebProcessConnection(WebProcessProxy* webProcessProxy, CoreIPC::ArgumentEncoder* reply)
{
    m_pendingConnectionReplies.append(make_pair(webProcessProxy, reply));

    if (m_processLauncher->isLaunching()) {
        m_numPendingConnectionRequests++;
        return;
    }

    // Ask the plug-in process to create a connection. Since the plug-in can be waiting for a synchronous reply
    // we need to make sure that this message is always processed, even when the plug-in is waiting for a synchronus reply.
    m_connection->send(Messages::PluginProcess::CreateWebProcessConnection(), 0, CoreIPC::DispatchMessageEvenWhenWaitingForSyncReply);
}