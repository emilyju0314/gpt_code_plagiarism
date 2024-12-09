void Service::checkModule(const IMessagePtr& in,
                          const IMessagePtr& out)
{
    BOOST_ASSERT(in);
    BOOST_ASSERT(out);

    const std::string mod_id = in->getValue(msg::key::SRVMODID);
    BOOST_ASSERT(mod_id.empty() == false);

    if (getFactory()->getModuleFactory()->isLoaded(mod_id))
    {
        // module is loaded
        out->setData(msg::key::SRVMODSTATUS, msg::key::OK);
    }
    else if  (getAppInfo(mod_id))
    {
        // application is loaded
        out->setData(msg::key::SRVMODSTATUS, msg::key::OK);
    }
    else
    {
        // nothing was loaded
        out->setData(msg::key::SRVMODSTATUS, msg::key::FAILED);
    }
}