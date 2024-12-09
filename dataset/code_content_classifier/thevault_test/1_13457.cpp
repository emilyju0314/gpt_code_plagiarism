const CLIAppTest::StringBoolMap CLIAppTest::getApps()
{
    db::Parameters params_select;
    params_select.add("@host");
    db::ResultVector rv =
        m_db->callSelect("klk_application_list", params_select, NULL);
    StringBoolMap map;
    for (db::ResultVector::iterator i = rv.begin(); i != rv.end(); i++)
    {
        //SELECT application, module, name, enabled, status, priority,
        // host, description
        const std::string app = (*i)["name"].toString();
        bool enabled = ((*i)["enabled"].toInt() != 0);
        map[app] = enabled;
    }
    return map;
}