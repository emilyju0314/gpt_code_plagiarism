TEST_F(
    VulkanLayerControllerTest,
    WillCreateDispatchTableAndVulkanLayerProducerOnCreateInstanceWithGameAlreadyEnablingRequiredExtensions) {
  std::unique_ptr<VulkanLayerControllerImpl> controller =
      std::make_unique<VulkanLayerControllerImpl>();
  const MockDispatchTable* dispatch_table = controller->dispatch_table();
  const MockSubmissionTracker* submission_tracker = controller->submission_tracker();
  const MockVulkanWrapper* vulkan_wrapper = controller->vulkan_wrapper();
  EXPECT_CALL(*dispatch_table, CreateInstanceDispatchTable).Times(1);
  EXPECT_CALL(*submission_tracker, SetVulkanLayerProducer).Times(1);

  EXPECT_CALL(*vulkan_wrapper, CallVkEnumerateInstanceExtensionProperties)
      .Times(2)
      .WillRepeatedly(Invoke([](const char* /*layer_name*/, uint32_t* property_count,
                                VkExtensionProperties* properties) -> VkResult {
        CHECK(property_count != nullptr);
        if (properties == nullptr) {
          *property_count = 1;
          return VK_SUCCESS;
        }
        VkExtensionProperties p{VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME,
                                VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_SPEC_VERSION};
        *properties = p;
        return VK_SUCCESS;
      }));

  static constexpr PFN_vkCreateInstance kMockDriverCreateInstance =
      +[](const VkInstanceCreateInfo* create_info, const VkAllocationCallbacks* /*allocator*/,
          VkInstance* /*instance*/) {
        bool requested_get_physical_device_properties_extension = false;
        for (uint32_t i = 0; i < create_info->enabledExtensionCount; ++i) {
          if (strcmp(create_info->ppEnabledExtensionNames[i],
                     VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) == 0) {
            requested_get_physical_device_properties_extension = true;
            break;
          }
        }
        EXPECT_TRUE(requested_get_physical_device_properties_extension);
        return VK_SUCCESS;
      };

  PFN_vkGetInstanceProcAddr fake_get_instance_proc_addr =
      +[](VkInstance /*instance*/, const char* name) -> PFN_vkVoidFunction {
    if (strcmp(name, "vkCreateInstance") == 0) {
      return absl::bit_cast<PFN_vkVoidFunction>(kMockDriverCreateInstance);
    }
    return nullptr;
  };

  std::string requested_extension_name = VK_EXT_HOST_QUERY_RESET_EXTENSION_NAME;
  std::vector<const char*> requested_extensions{};
  requested_extensions.push_back(requested_extension_name.c_str());

  VkLayerInstanceLink layer_link_1 = {.pfnNextGetInstanceProcAddr = fake_get_instance_proc_addr};
  VkLayerInstanceCreateInfo layer_create_info{
      .sType = VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO, .function = VK_LAYER_LINK_INFO};
  layer_create_info.u.pLayerInfo = &layer_link_1;
  VkInstanceCreateInfo create_info{.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                                   .pNext = &layer_create_info,
                                   .enabledExtensionCount = 1,
                                   .ppEnabledExtensionNames = requested_extensions.data()};

  VkInstance created_instance;
  VkResult result = controller->OnCreateInstance(&create_info, nullptr, &created_instance);
  EXPECT_EQ(result, VK_SUCCESS);
  ::testing::Mock::VerifyAndClearExpectations(absl::bit_cast<void*>(submission_tracker));
  // There will be a call in the destructor.
  auto actual_producer = absl::bit_cast<VulkanLayerProducer*>(static_cast<uintptr_t>(0xdeadbeef));
  EXPECT_CALL(*submission_tracker, SetVulkanLayerProducer)
      .Times(1)
      .WillOnce(SaveArg<0>(&actual_producer));
  controller.reset();
  EXPECT_EQ(actual_producer, nullptr);
}