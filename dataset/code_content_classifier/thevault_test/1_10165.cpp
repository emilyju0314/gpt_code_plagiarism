app_setting* app_setting_manager::find (std::string const& key)
{
    for (auto setting : get_settings())
    {
        if (equal_ignore_case(setting->key, key))
        {
            return setting;
        }
    }
    return nullptr;
}