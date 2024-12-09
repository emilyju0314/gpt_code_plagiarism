bool VkRenderFramework::InstanceExtensionSupported(const char *ext_name, uint32_t spec) {
    uint32_t ext_count = 0;
    std::vector<VkExtensionProperties> ext_props;
    VkResult res = vkEnumerateInstanceExtensionProperties(nullptr, &ext_count, nullptr);
    if (VK_SUCCESS != res) return false;
    if (0 == ext_count) return false;

    ext_props.resize(ext_count);
    res = vkEnumerateInstanceExtensionProperties(nullptr, &ext_count, ext_props.data());
    if (VK_SUCCESS != res) return false;

    for (auto &it : ext_props) {
        if (0 == strncmp(ext_name, it.extensionName, VK_MAX_EXTENSION_NAME_SIZE)) {
            return (it.specVersion >= spec);
        }
    }
    return false;
}