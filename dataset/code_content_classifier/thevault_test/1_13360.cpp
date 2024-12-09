const AppInfoPtr Service::getAppInfo(const std::string& mod_id) const
{
    AppInfoList list = m_apps.getAll();
    AppInfoList::iterator find = std::find_if(list.begin(), list.end(),
                                              boost::bind<bool>(FindAppInfoByModID(), _1, mod_id));
    if (find != list.end())
    {
        return *find;
    }

    return AppInfoPtr();
}