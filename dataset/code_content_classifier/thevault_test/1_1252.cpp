void HelloVulkan::createLanternModel()
{
  std::vector<nvmath::vec3f> vertices;
  std::vector<uint32_t>      indices;
  fillLanternVerts(vertices, indices);

  // Upload vertex and index data to buffers.
  auto usageFlags = VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT;
  auto memFlags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;

  auto vertexBytes      = vertices.size() * sizeof vertices[0];
  m_lanternVertexBuffer = m_alloc.createBuffer(vertexBytes, usageFlags, memFlags);
  void* map             = m_alloc.map(m_lanternVertexBuffer);
  memcpy(map, vertices.data(), vertexBytes);
  m_alloc.unmap(m_lanternVertexBuffer);

  auto indexBytes      = indices.size() * sizeof indices[0];
  m_lanternIndexBuffer = m_alloc.createBuffer(indexBytes, usageFlags, memFlags);
  map                  = m_alloc.map(m_lanternIndexBuffer);
  memcpy(map, indices.data(), indexBytes);
  m_alloc.unmap(m_lanternIndexBuffer);

  // Package vertex and index buffers as BlasInput.
  VkDeviceAddress vertexAddress = nvvk::getBufferDeviceAddress(m_device, m_lanternVertexBuffer.buffer);
  VkDeviceAddress indexAddress  = nvvk::getBufferDeviceAddress(m_device, m_lanternIndexBuffer.buffer);

  auto maxPrimitiveCount = uint32_t(indices.size() / 3);

  // Describe buffer as packed array of float vec3.
  VkAccelerationStructureGeometryTrianglesDataKHR triangles{VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR};
  triangles.vertexFormat             = VK_FORMAT_R32G32B32_SFLOAT;  // vec3 vertex position data.
  triangles.vertexData.deviceAddress = vertexAddress;
  triangles.vertexStride             = sizeof(nvmath::vec3f);
  // Describe index data (32-bit unsigned int)
  triangles.indexType               = VK_INDEX_TYPE_UINT32;
  triangles.indexData.deviceAddress = indexAddress;
  // Indicate identity transform by setting transformData to null device pointer.
  //triangles.transformData = {};
  triangles.maxVertex = uint32_t(vertices.size());

  // Identify the above data as containing opaque triangles.
  VkAccelerationStructureGeometryKHR asGeom{VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR};
  asGeom.geometryType       = VK_GEOMETRY_TYPE_TRIANGLES_KHR;
  asGeom.flags              = VK_GEOMETRY_OPAQUE_BIT_KHR;
  asGeom.geometry.triangles = triangles;

  // The entire array will be used to build the BLAS.
  VkAccelerationStructureBuildRangeInfoKHR offset;
  offset.firstVertex     = 0;
  offset.primitiveCount  = maxPrimitiveCount;
  offset.primitiveOffset = 0;
  offset.transformOffset = 0;

  // Our blas is made from only one geometry, but could be made of many geometries
  m_lanternBlasInput.asGeometry.emplace_back(asGeom);
  m_lanternBlasInput.asBuildOffsetInfo.emplace_back(offset);
}