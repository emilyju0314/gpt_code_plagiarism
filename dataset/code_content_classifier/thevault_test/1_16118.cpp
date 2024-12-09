static void loadConfig() {
    g_reshade_dll_path = getModulePath(g_reshade_module_handle);
    Logfile::get()->writeInfo(std::string() + "g_reshade_dll_path:" + g_reshade_dll_path.generic_u8string());

    // Parse the ReShade config file and get the used settings for the generic depth plugin.
    std::vector<std::string> preprocessorDefinitions;
    reshade::global_config().get("GENERAL", "PreprocessorDefinitions", preprocessorDefinitions);
    for (const std::string& preprocessorDefinition : preprocessorDefinitions) {
        auto equalSignPos = preprocessorDefinition.find("=");
        if (equalSignPos == std::string::npos) {
            continue;
        }
        std::string key = preprocessorDefinition.substr(0, equalSignPos);
        std::string value = preprocessorDefinition.substr(equalSignPos + 1);
        Logfile::get()->writeInfo("key: " + key + ", value: " + value);

        if (key == "RESHADE_DEPTH_INPUT_IS_UPSIDE_DOWN") {
            isDepthUpsideDown = fromString<int>(value.c_str());
        } else if (key == "RESHADE_DEPTH_INPUT_IS_REVERSED") {
            isDepthReversed = fromString<int>(value.c_str());
        } else if (key == "RESHADE_DEPTH_INPUT_IS_LOGARITHMIC") {
            isDepthLogarithmic = fromString<int>(value.c_str());
        } else if (key == "RESHADE_DEPTH_LINEARIZATION_FAR_PLANE") {
            farPlaneDist = fromString<float>(value.c_str());
        }
    }
}