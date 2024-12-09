bool VkRenderFramework::InstanceLayerSupported(const char *name, uint32_t spec, uint32_t implementation) {
    uint32_t layer_count = 0;
    std::vector<VkLayerProperties> layer_props;

    VkResult res = vkEnumerateInstanceLayerProperties(&layer_count, NULL);
    if (VK_SUCCESS != res) return false;
    if (0 == layer_count) return false;

    layer_props.resize(layer_count);
    res = vkEnumerateInstanceLayerProperties(&layer_count, layer_props.data());
    if (VK_SUCCESS != res) return false;

    for (auto &it : layer_props) {
        if (0 == strncmp(name, it.layerName, VK_MAX_EXTENSION_NAME_SIZE)) {
            return ((it.specVersion >= spec) && (it.implementationVersion >= implementation));
        }
    }
    return false;
}