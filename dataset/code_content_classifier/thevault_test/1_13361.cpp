void Service::updateCPUUsage4App(const IMessagePtr& in)
{
    BOOST_ASSERT(in);
    const std::string mod_id = in->getValue(msg::key::SRVMODID);
    BOOST_ASSERT(mod_id.empty() == false);
    AppInfoPtr info = getAppInfo(mod_id);
    const std::string cpu_usage = in->getValue(msg::key::SRVMODCPUUSAGE);
    BOOST_ASSERT(cpu_usage.empty() == false);
    info->setCPUUsage(cpu_usage);
}