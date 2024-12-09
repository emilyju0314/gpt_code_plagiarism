TEST_F(
    VulkanLayerControllerTest,
    WillCreateDispatchTableAndVulkanLayerProducerAndAdvanceLinkageOnCreateDeviceWithGameNotEnablingRequiredExtensions) {
  const MockDispatchTable* dispatch_table = controller_.dispatch_table();
  EXPECT_CALL(*dispatch_table, CreateDeviceDispatchTable).Times(1);
  const MockDeviceManager* device_manager = controller_.device_manager();
  EXPECT_CALL(*device_manager, TrackLogicalDevice).Times(1);
  const MockTimerQueryPool* timer_query_pool = controller_.timer_query_pool();
  EXPECT_CALL(*timer_query_pool, InitializeTimerQueryPool).Times(1);

  static constexpr PFN_vkCreateDevice kMockDriverCreateDevice =
      +[](VkPhysicalDevice /*physical_device*/, const VkDeviceCreateInfo* create_info,
          const VkAllocationCallbacks* /*allocator*/, VkDevice* /*instance*/) {
        bool requested_host_extension = false;
        for (uint32_t i = 0; i < create_info->enabledExtensionCount; ++i) {
          if (strcmp(create_info->ppEnabledExtensionNames[i],
                     VK_EXT_HOST_QUERY_RESET_EXTENSION_NAME) == 0) {
            requested_host_extension = true;
            break;
          }
        }
        EXPECT_TRUE(requested_host_extension);
        return VK_SUCCESS;
      };
  static constexpr PFN_vkEnumerateDeviceExtensionProperties
      kFakeEnumerateDeviceExtensionProperties =
          +[](VkPhysicalDevice /*physical_device*/, const char* /*layer_name*/,
              uint32_t* property_count, VkExtensionProperties* properties) -> VkResult {
    CHECK(property_count != nullptr);
    if (properties == nullptr) {
      *property_count = 1;
      return VK_SUCCESS;
    }
    VkExtensionProperties p{VK_EXT_HOST_QUERY_RESET_EXTENSION_NAME,
                            VK_EXT_HOST_QUERY_RESET_SPEC_VERSION};
    *properties = p;
    return VK_SUCCESS;
  };

  PFN_vkGetDeviceProcAddr fake_get_device_proc_addr =
      +[](VkDevice /*device*/, const char * /*name*/) -> PFN_vkVoidFunction { return nullptr; };

  PFN_vkGetInstanceProcAddr fake_get_instance_proc_addr =
      +[](VkInstance /*instance*/, const char* name) -> PFN_vkVoidFunction {
    if (strcmp(name, "vkCreateDevice") == 0) {
      return absl::bit_cast<PFN_vkVoidFunction>(kMockDriverCreateDevice);
    }
    if (strcmp(name, "vkEnumerateDeviceExtensionProperties") == 0) {
      return absl::bit_cast<PFN_vkVoidFunction>(kFakeEnumerateDeviceExtensionProperties);
    }
    return nullptr;
  };

  VkLayerDeviceLink layer_link_1 = {.pfnNextGetInstanceProcAddr = fake_get_instance_proc_addr,
                                    .pfnNextGetDeviceProcAddr = fake_get_device_proc_addr};
  VkLayerDeviceLink layer_link_2 = {
      .pNext = &layer_link_1,
      .pfnNextGetInstanceProcAddr = fake_get_instance_proc_addr,
      .pfnNextGetDeviceProcAddr = fake_get_device_proc_addr,
  };
  VkLayerDeviceCreateInfo layer_create_info{.sType = VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO,
                                            .function = VK_LAYER_LINK_INFO};
  layer_create_info.u.pLayerInfo = &layer_link_2;
  VkDeviceCreateInfo create_info{.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
                                 .pNext = &layer_create_info,
                                 .enabledExtensionCount = 0,
                                 .ppEnabledExtensionNames = nullptr};
  VkDevice created_device;
  VkPhysicalDevice physical_device = {};
  VkResult result =
      controller_.OnCreateDevice(physical_device, &create_info, nullptr, &created_device);
  EXPECT_EQ(result, VK_SUCCESS);
  EXPECT_EQ(layer_create_info.u.pLayerInfo, &layer_link_1);
}