std::string app_setting_manager::get_value (std::string const& key)
{
    app_setting const* setting = find(std::move(key));
    return ( setting != nullptr ? setting->value : "" );
}