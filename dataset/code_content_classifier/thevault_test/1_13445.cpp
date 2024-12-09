void Adapter::registerRemoteMessage(const std::string& msg_id,
                                    const std::string& mod_id,
                                    msg::Type msg_type)
{
    {
        klk::Locker lock(&m_remote_mutex);
        // check that the module id has not been registered yet
        StringList ids = m_remote_messages[msg_id];
        if (std::find(ids.begin(), ids.end(), mod_id) == ids.end())
        {
            m_remote_messages[msg_id].push_back(mod_id);
        }
        else
        {
            // has been registered already
            klk_log(KLKLOG_ERROR, "The remote message '%s' for module '%s' "
                    "has been already registered at adapter module",
                    msg_id.c_str(), mod_id.c_str());
            return; // nothing to do
        }
    }

    switch (msg_type)
    {
    case msg::ASYNC:
        registerASync(msg_id, boost::bind(&Adapter::processRemoteASync, this, _1));
        break;
    case msg::SYNC_REQ:
        registerSync(msg_id, boost::bind(&Adapter::processRemoteSync, this, _1, _2));
        break;
    default:
        BOOST_ASSERT(false);
        break;
    }
}