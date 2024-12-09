void app_setting_manager::add_or_update_value (std::string const& key, std::string const& value)
{
    app_setting* setting = find(key);
    
    if (setting == nullptr) {
        // add a new setting
        add_value(key, value);
    } else {
        // update the existing setting
        setting->value = value;
    }
    
    save_and_reload();
}