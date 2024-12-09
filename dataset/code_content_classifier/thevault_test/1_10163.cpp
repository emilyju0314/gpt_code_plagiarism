void app_setting_manager::add_value (std::string key, std::string value)
{
    auto setting = new app_setting;
    setting->key   = std::move(key);
    setting->value = std::move(value);
    
    settings_.push_back(setting);
    save_and_reload();
}