void HelloVulkan::addLantern(nvmath::vec3f pos, nvmath::vec3f color, float brightness, float radius)
{
  assert(m_lanternCount == 0);  // Indicates TLAS build has not happened yet.

  m_lanterns.push_back({pos, color, brightness, radius});
}