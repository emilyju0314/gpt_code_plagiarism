bool VkRenderFramework::DeviceExtensionSupported(VkPhysicalDevice dev, const char *layer, const char *ext_name, uint32_t spec) {
    if (!inst) {
        EXPECT_NE((VkInstance)0, inst);  // Complain, not cool without an instance
        return false;
    }
    uint32_t ext_count = 0;
    std::vector<VkExtensionProperties> ext_props;
    VkResult res = vkEnumerateDeviceExtensionProperties(dev, layer, &ext_count, nullptr);
    if (VK_SUCCESS != res) return false;
    if (0 == ext_count) return false;

    ext_props.resize(ext_count);
    res = vkEnumerateDeviceExtensionProperties(dev, layer, &ext_count, ext_props.data());
    if (VK_SUCCESS != res) return false;

    for (auto &it : ext_props) {
        if (0 == strncmp(ext_name, it.extensionName, VK_MAX_EXTENSION_NAME_SIZE)) {
            return (it.specVersion >= spec);
        }
    }
    return false;
}