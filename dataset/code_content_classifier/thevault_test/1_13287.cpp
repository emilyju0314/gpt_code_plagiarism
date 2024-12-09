void Launcher::checkRPC()
{
    using namespace klk::adapter;
    try
    {
        ResourcesProtocol res_proto(m_factory);
        if (res_proto.checkConnection() != klk::OK)
        {
            throw klk::Exception(__FILE__, __LINE__,
                                 "Resources RPC is not available");
        }

        DevProtocol dev_proto(m_factory);
        if (dev_proto.checkConnection() != klk::OK)
        {
            throw klk::Exception(__FILE__, __LINE__,
                                 "Dev RPC is not available");
        }

        MessagesProtocol msg_proto(m_factory);
        if (msg_proto.checkConnection() != klk::OK)
        {
            throw klk::Exception(__FILE__, __LINE__,
                                 "Messages RPC is not available");
        }

        ModulesProtocol mod_proto(m_factory);
        if (mod_proto.checkConnection() != klk::OK)
        {
            throw klk::Exception(__FILE__, __LINE__,
                                 "Modules RPC is not available");
        }
    }
    catch(...)
    {
        klk_log(KLKLOG_ERROR, "RPC check failed");
        throw;
    }
}