bool VkRenderFramework::InstanceExtensionEnabled(const char *ext_name) {
    if (!inst) return false;

    bool ext_found = false;
    for (auto ext : m_instance_extension_names) {
        if (!strcmp(ext, ext_name)) {
            ext_found = true;
            break;
        }
    }
    return ext_found;
}