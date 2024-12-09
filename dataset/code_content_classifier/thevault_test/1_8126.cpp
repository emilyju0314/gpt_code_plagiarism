inline static glm::quat GetRotationOnPlane(const glm::quat& rotation,
                                           const glm::vec3& plane_normal) {
  const glm::vec3 world_up = glm::vec3(0.0f, 1.0f, 0.0f);

  // The transformed up vector for the device.
  glm::vec3 transformed = glm::rotate(rotation, world_up);

  // Project transformed vector onto plane.
  glm::vec3 flattened = glm::normalize(
      world_up - (glm::dot(world_up, plane_normal) * plane_normal));

  // Get angle between original vector and projected transform to get angle
  // around normal.
  return glm::rotation(transformed, flattened);
}