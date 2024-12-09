bool SecureAIParams::from_string(const std::string &str, SecureAIParams &result)
{
    std::vector<std::string> our_fields = {"model_managment_server_url", "name", "version", "enabled", "download_from_model_management_server", "model_url"};
    std::vector<std::string> fields = util::splice_comma_separated_list(str);
    if (fields.size() != our_fields.size())
    {
        return false;
    }

    result.model_management_server_url = fields.at(0);
    result.model_name = fields.at(1);
    result.model_version = fields.at(2);
    result.secure_ai_lifecycle_enabled = (fields.at(3) == "true");
    result.download_from_model_management_server = (fields.at(4) == "true");
    result.model_url = fields.at(5);

    return true;
}