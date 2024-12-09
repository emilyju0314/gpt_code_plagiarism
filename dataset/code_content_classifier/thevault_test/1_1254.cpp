void HelloVulkan::createTopLevelAS()
{
  assert(m_lanternCount == 0);
  m_lanternCount = m_lanterns.size();

  std::vector<VkAccelerationStructureInstanceKHR> tlas;
  tlas.reserve(m_instances.size() + m_lanternCount);

  // Add the OBJ instances.
  for(const HelloVulkan::ObjInstance& inst : m_instances)
  {
    VkAccelerationStructureInstanceKHR rayInst{};
    rayInst.transform                      = nvvk::toTransformMatrixKHR(inst.transform);  // Position of the instance
    rayInst.instanceCustomIndex            = inst.objIndex;                               // gl_InstanceCustomIndexEXT
    rayInst.accelerationStructureReference = m_rtBuilder.getBlasDeviceAddress(inst.objIndex);
    rayInst.flags                          = VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR;
    rayInst.mask                           = 0xFF;       //  Only be hit if rayMask & instance.mask != 0
    rayInst.instanceShaderBindingTableRecordOffset = 0;  // We will use the same hit group for all objects
    tlas.emplace_back(rayInst);
  }

  // Add lantern instances.
  for(int i = 0; i < static_cast<int>(m_lanterns.size()); ++i)
  {
    VkAccelerationStructureInstanceKHR lanternInstance;
    lanternInstance.transform           = nvvk::toTransformMatrixKHR(nvmath::translation_mat4(m_lanterns[i].position));
    lanternInstance.instanceCustomIndex = i;
    lanternInstance.accelerationStructureReference = m_rtBuilder.getBlasDeviceAddress(uint32_t(m_lanternBlasId));
    lanternInstance.instanceShaderBindingTableRecordOffset = 1;  // Next hit group is for lanterns.
    lanternInstance.flags                                  = VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR;
    lanternInstance.mask                                   = 0xFF;
    tlas.emplace_back(lanternInstance);
  }

  m_rtBuilder.buildTlas(tlas, VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR);
}