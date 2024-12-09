std::string SecureAIParams::to_string() const
{
    std::stringstream str;
    str << this->model_management_server_url << "," << this->model_name << "," << this->model_version << "," << (this->secure_ai_lifecycle_enabled ? "true" : "false") << "," << (this->download_from_model_management_server ? "true" : "false") << "," << this->model_url;
    return str.str();
}