void TestService::sendSigSegv(const std::string& app_id)
{
    ServicePtr system = this->getModule<Service>(MODID);
    AppInfoList list = system->m_apps.getAll();
    for (AppInfoList::iterator item = list.begin();
         item != list.end(); item++)
    {
        if ((*item)->getAppUUID() == app_id)
        {
            // send SIGSEGV
            kill((*item)->getPid(), SIGSEGV);
            break;
        }
    }
}