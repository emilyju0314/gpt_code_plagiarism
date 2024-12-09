bool VkRenderFramework::DeviceIsMockICD() {
    VkPhysicalDeviceProperties props = vk_testing::PhysicalDevice(gpu()).properties();
    if ((props.vendorID == 0xba5eba11) && (props.deviceID == 0xf005ba11) && (0 == strcmp("Vulkan Mock Device", props.deviceName))) {
        return true;
    }
    return false;
}