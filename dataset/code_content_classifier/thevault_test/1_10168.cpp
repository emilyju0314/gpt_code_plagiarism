void app_setting_manager::load_settings ()
{
    settings_.clear();
    std::string line;
    std::ifstream reader(file_name_);
    
    if (reader.is_open())
    {
        while (getline(reader, line))
        {
            vstring_t parts = split(line, '|');
            auto item = new app_setting;
            
            item->key   = parts[0];
            item->value = (parts.size() > 1) ? parts[1] : "";
            
            settings_.push_back(item);
        }
        reader.close();
    }
}