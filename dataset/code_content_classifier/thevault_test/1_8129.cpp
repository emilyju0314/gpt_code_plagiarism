void DepthImage::UpdateAndUpsampleDepth(
    const glm::mat4& color_t1_T_depth_t0,
    const TangoPointCloud* render_point_cloud_buffer) {
  int depth_image_width = rgb_camera_intrinsics_.width;
  int depth_image_height = rgb_camera_intrinsics_.height;
  int depth_image_size = depth_image_width * depth_image_height;

  depth_map_buffer_.resize(depth_image_size);
  grayscale_display_buffer_.resize(depth_image_size);
  std::fill(depth_map_buffer_.begin(), depth_map_buffer_.end(), 0);
  std::fill(grayscale_display_buffer_.begin(), grayscale_display_buffer_.end(),
            0);

  int point_cloud_size = render_point_cloud_buffer->num_points;
  for (int i = 0; i < point_cloud_size; ++i) {
    float x = render_point_cloud_buffer->points[i][0];
    float y = render_point_cloud_buffer->points[i][1];
    float z = render_point_cloud_buffer->points[i][2];

    // depth_t0_point is the point in depth camera frame on timestamp t0.
    // (depth image timestamp).
    glm::vec4 depth_t0_point = glm::vec4(x, y, z, 1.0);

    // color_t1_point is the point in camera frame on timestamp t1.
    // (color image timestamp).
    glm::vec4 color_t1_point = color_t1_T_depth_t0 * depth_t0_point;

    int pixel_x, pixel_y;
    // get the coordinate on image plane.
    pixel_x = static_cast<int>((rgb_camera_intrinsics_.fx) *
                                   (color_t1_point.x / color_t1_point.z) +
                               rgb_camera_intrinsics_.cx);

    pixel_y = static_cast<int>((rgb_camera_intrinsics_.fy) *
                                   (color_t1_point.y / color_t1_point.z) +
                               rgb_camera_intrinsics_.cy);

    // Color value is the GL_LUMINANCE value used for displaying the depth
    // image.
    // We can query for depth value in mm from grayscale image buffer by
    // getting a `pixel_value` at (pixel_x,pixel_y) and calculating
    // pixel_value * (kMaxDepthDistance / USHRT_MAX)
    float depth_value = color_t1_point.z;
    uint8_t grayscale_value =
        (color_t1_point.z * kMeterToMillimeter) * UCHAR_MAX / kMaxDepthDistance;

    UpSampleDepthAroundPoint(grayscale_value, depth_value, pixel_x, pixel_y,
                             &grayscale_display_buffer_, &depth_map_buffer_);
  }

  this->CreateOrBindCPUTexture();
  glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, depth_image_width, depth_image_height,
                  GL_LUMINANCE, GL_UNSIGNED_BYTE,
                  grayscale_display_buffer_.data());
  tango_gl::util::CheckGlError("DepthImage glTexSubImage2D");
  glBindTexture(GL_TEXTURE_2D, 0);

  texture_id_ = cpu_texture_id_;
}