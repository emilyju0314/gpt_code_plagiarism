void PlaneFittingApplication::OnTouchEvent(float x, float y) {
  if (!is_gl_initialized_ || !is_service_connected_) {
    return;
  }

  // Get the latest point cloud
  TangoPointCloud* point_cloud = nullptr;
  TangoSupport_getLatestPointCloud(point_cloud_manager_, &point_cloud);
  if (point_cloud == nullptr) {
    return;
  }

  // Get pose from depth camera to color camera.
  TangoPoseData pose_depth_T_color;
  TangoErrorType ret;

  ret = TangoSupport_getPoseAtTime(
      last_gpu_timestamp_, TANGO_COORDINATE_FRAME_CAMERA_DEPTH,
      TANGO_COORDINATE_FRAME_CAMERA_COLOR, TANGO_SUPPORT_ENGINE_TANGO,
      TANGO_SUPPORT_ENGINE_TANGO, TANGO_SUPPORT_ROTATION_IGNORED,
      &pose_depth_T_color);
  if (ret != TANGO_SUCCESS) {
    LOGE("%s: could not get openglTcolor pose for last_gpu_timestamp_ %f.",
         __func__, last_gpu_timestamp_);
    return;
  }

  // Touch location in [0,1] range.
  glm::vec2 uv(x / screen_width_, y / screen_height_);
  double zero_vector[3] = {0.0f, 0.0f, 0.0f};
  double identity_quaternion[4] = {0.0f, 0.0f, 0.0f, 1.0f};

  glm::dvec4 out_plane_model;
  glm::dvec3 out_plane_intersect;

  if (TangoSupport_fitPlaneModelNearPoint(
          point_cloud, zero_vector, identity_quaternion, glm::value_ptr(uv),
          display_rotation_, pose_depth_T_color.translation,
          pose_depth_T_color.orientation, glm::value_ptr(out_plane_intersect),
          glm::value_ptr(out_plane_model)) != TANGO_SUCCESS) {
    // Assuming errors have already been reported.
    return;
  }

  plane_timestamp_ = last_gpu_timestamp_;

  // Use world up as the second vector unless they are nearly parallel, in
  // which case use world +Z.
  const glm::vec3 plane_normal(static_cast<float>(out_plane_model.x),
                               static_cast<float>(out_plane_model.y),
                               static_cast<float>(out_plane_model.z));

  glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
  const glm::vec3 z_axis = glm::normalize(plane_normal);
  const glm::vec3 x_axis = glm::normalize(glm::cross(up, z_axis));
  const glm::vec3 y_axis = glm::normalize(glm::cross(z_axis, x_axis));

  glm::vec3 normal_offeset = z_axis * kCubeScale;
  depth_T_plane_[0] = glm::vec4(x_axis.x, x_axis.y, x_axis.z, 0.0f);
  depth_T_plane_[1] = glm::vec4(y_axis.x, y_axis.y, y_axis.z, 0.0f);
  depth_T_plane_[2] = glm::vec4(z_axis.x, z_axis.y, z_axis.z, 0.0f);
  depth_T_plane_[3][0] =
      static_cast<float>(out_plane_intersect.x) + normal_offeset.x;
  depth_T_plane_[3][1] =
      static_cast<float>(out_plane_intersect.y) + normal_offeset.y;
  depth_T_plane_[3][2] =
      static_cast<float>(out_plane_intersect.z) + normal_offeset.z;
  is_cube_placed_ = true;
}