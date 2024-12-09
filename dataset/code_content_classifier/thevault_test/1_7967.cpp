bool VkRenderFramework::EnableDeviceProfileLayer() {
    if (InstanceLayerSupported("VK_LAYER_LUNARG_device_profile_api")) {
        if (VkTestFramework::m_devsim_layer) {
            assert(0 == strcmp(m_instance_layer_names.back(), "VK_LAYER_LUNARG_device_simulation"));
            m_instance_layer_names.pop_back();
            m_instance_layer_names.push_back("VK_LAYER_LUNARG_device_profile_api");
        } else {
            m_instance_layer_names.push_back("VK_LAYER_LUNARG_device_profile_api");
        }
    } else {
        printf("             Did not find VK_LAYER_LUNARG_device_profile_api layer; skipped.\n");
        return false;
    }
    return true;
}