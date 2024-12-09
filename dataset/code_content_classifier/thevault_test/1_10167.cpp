void app_setting_manager::save_settings ()
{
    std::ofstream writter(file_name_);
    for (const auto setting : settings_)
    {
        writter << setting->key << "|";
        writter << setting->value << std::endl;
    }
}