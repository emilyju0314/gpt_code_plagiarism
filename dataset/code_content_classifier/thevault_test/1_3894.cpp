static void parse_model_update(JSON_Object *root_object)
{
    std::string model_name = "";
    std::string model_version = "";
    std::string mm_server_url = "";
    std::string model_url = "";
    bool enable_secure_ai = false;
    bool download_model_from_mm_server = true;
    bool parameters_changed = false; // We don't want to update the model unless we changed something about its configuration

    if (json_object_dotget_value(root_object, "desired.SCZ_MODEL_NAME") != nullptr)
    {
        model_name = json_object_dotget_string(root_object, "desired.SCZ_MODEL_NAME");
    }
    if (json_object_get_value(root_object, "SCZ_MODEL_NAME") != nullptr)
    {
        model_name = json_object_get_string(root_object, "SCZ_MODEL_NAME");
    }

    if (json_object_dotget_value(root_object, "desired.SCZ_MODEL_VERSION") != nullptr)
    {
        model_version = json_object_dotget_string(root_object, "desired.SCZ_MODEL_VERSION");
    }
    if (json_object_get_value(root_object, "SCZ_MODEL_VERSION") != nullptr)
    {
        model_version = json_object_get_string(root_object, "SCZ_MODEL_VERSION");
    }

    if (json_object_dotget_value(root_object, "desired.SCZ_MM_SERVER_URL") != nullptr)
    {
        mm_server_url = json_object_dotget_string(root_object, "desired.SCZ_MM_SERVER_URL");
    }
    if (json_object_get_value(root_object, "SCZ_MM_SERVER_URL") != nullptr)
    {
        mm_server_url = json_object_get_string(root_object, "SCZ_MM_SERVER_URL");
    }

    if (json_object_dotget_value(root_object, "desired.SecureAILifecycleEnabled") != nullptr)
    {
        enable_secure_ai = json_object_dotget_boolean(root_object, "desired.SecureAILifecycleEnabled");
    }
    if (json_object_get_value(root_object, "SecureAILifecycleEnabled") != nullptr)
    {
        enable_secure_ai = json_object_get_boolean(root_object, "SecureAILifecycleEnabled");
    }

    if (json_object_dotget_value(root_object, "desired.DownloadSecuredModelFromMMServer") != nullptr)
    {
        download_model_from_mm_server = json_object_dotget_boolean(root_object, "desired.DownloadSecuredModelFromMMServer");
    }
    if (json_object_get_value(root_object, "DownloadSecuredModelFromMMServer") != nullptr)
    {
        download_model_from_mm_server = json_object_get_boolean(root_object, "DownloadSecuredModelFromMMServer");
    }

    if (json_object_dotget_value(root_object, "desired.ModelZipUrl") != nullptr)
    {
        model_url = json_object_dotget_string(root_object, "desired.ModelZipUrl");
    }
    if (json_object_get_value(root_object, "ModelZipUrl") != nullptr)
    {
        model_url = json_object_get_string(root_object, "ModelZipUrl");
    }

    // BLOCKS until it can get the mutex for the secure AI params.
    util::log_debug("Accessing update_secure_model_params mutex from IoT update.");
    parameters_changed = secure::update_secure_model_params(mm_server_url, model_name, model_version, enable_secure_ai, download_model_from_mm_server, model_url);
    util::log_debug("Done accessing update_secure_model_params mutex from IoT update.");

    if (enable_secure_ai && parameters_changed)
    {
        if (!model_name.empty() && !model_version.empty() && !mm_server_url.empty())
        {
            if (download_model_from_mm_server || (!download_model_from_mm_server && !model_url.empty()))
            {
                // We have enabled secure AI and we find the model config changes from the previous version. So we should update using the secure route now.
                // BLOCKS until it can get the mutex for the secure AI params.
                util::log_debug("Accessing get_model_params mutex from IoT update.");
                update_model(secure::get_model_params());
                util::log_debug("Done accessing get_model_params mutex from IoT Update.");
            }
            else
            {
                util::log_error("Invalid secured AI model configuration. The value of \"ModelZipUrl\" should not be empty if download the model from external URL.");
            }
        }
        else
        {
            util::log_error("Invalid secured AI model configuration. The value of \"SCZ_MODEL_NAME\", \"SCZ_MODEL_VERSION\" and \"SCZ_MM_SERVER_URL\" should not be empty.");
        }
    }
    else if (!enable_secure_ai && parameters_changed)
    {
        // We have disabled secure AI and and we find the model config changes from the previous version. So we should update using the normal route now.
        update_model(model_url);
    }
}