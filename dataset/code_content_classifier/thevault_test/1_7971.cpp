bool VkRenderFramework::DeviceExtensionEnabled(const char *ext_name) {
    if (NULL == m_device) return false;

    bool ext_found = false;
    for (auto ext : m_device_extension_names) {
        if (!strcmp(ext, ext_name)) {
            ext_found = true;
            break;
        }
    }
    return ext_found;
}