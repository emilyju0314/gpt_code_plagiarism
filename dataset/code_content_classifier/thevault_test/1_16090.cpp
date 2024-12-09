bool parseUnderscore(const std::string& value)
{
    size_t i = value.find_first_of('_');
    return (i != std::string::npos && i == value.find_last_of('_')
            && value.find_first_not_of(" _") == std::string::npos);
}