void calculateFOV(float h_fov, float v_fov, FOV_indices& FOV,
                  float yaw_deg_histogram_frame, float pitch_deg) {
  PolarPoint max_angle(pitch_deg + v_fov / 2.0f,
                       yaw_deg_histogram_frame + h_fov / 2.0f, 1.f);
  PolarPoint min_angle(pitch_deg - v_fov / 2.0f,
                       yaw_deg_histogram_frame - h_fov / 2.0f, 1.f);
  Eigen::Vector2i max_ind = polarToHistogramIndex(max_angle, ALPHA_RES);
  Eigen::Vector2i min_ind = polarToHistogramIndex(min_angle, ALPHA_RES);

  FOV.e_idx_max = max_ind.y();
  FOV.e_idx_min = min_ind.y();

  // indices not wrapped
  if (max_ind.x() > min_ind.x()) {
    for (int i = min_ind.x(); i <= max_ind.x(); i++) {
      FOV.z_idx_vec.push_back(i);
    }
  }

  // indices wrapped
  if (min_ind.x() > max_ind.x()) {
    for (int i = 0; i <= max_ind.x(); i++) {
      FOV.z_idx_vec.push_back(i);
    }
    for (int i = min_ind.x(); i < GRID_LENGTH_Z; i++) {
      FOV.z_idx_vec.push_back(i);
    }
  }
}