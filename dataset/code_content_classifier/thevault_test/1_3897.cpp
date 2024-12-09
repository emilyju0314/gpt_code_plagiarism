static void module_twin_callback(DEVICE_TWIN_UPDATE_STATE update_state, const unsigned char *payload, size_t size, void *user_context_cb)
{
    util::log_info("module twin callback called with (state=" + std::string(MU_ENUM_TO_STRING(DEVICE_TWIN_UPDATE_STATE, update_state)) + ", size=" + std::to_string(size) + "): " + reinterpret_cast<const char*>(payload));

    JSON_Value *root_value = json_parse_string(reinterpret_cast<const char*>(payload));
    JSON_Object *root_object = json_value_get_object(root_value);

    // Parse out all the stuff and deal with it
    parse_logging(root_object);
    parse_retraining(root_object);
    parse_telemetry(root_object);
    parse_model_update(root_object);
    parse_streams(root_object);
    parse_time_alignment(root_object);
}