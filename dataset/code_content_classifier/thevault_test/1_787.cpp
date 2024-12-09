ORB::ORB(size_t n_features, const CommonParams & detector_params) :
  params_(detector_params), n_features_(n_features)
{
  // fill the extractors and descriptors for the corresponding scales
  float factor = (float)(1.0 / params_.scale_factor_ / params_.scale_factor_);
  int n_desired_features_per_scale = cvRound(n_features / ((std::pow(factor, int(params_.n_levels_)) - 1)
                                                 / (factor - 1)));
  n_features_per_level_.resize(detector_params.n_levels_);
  for (unsigned int level = 0; level < detector_params.n_levels_; level++)
  {
    n_features_per_level_[level] = n_desired_features_per_scale;
    n_desired_features_per_scale = cvRound(n_desired_features_per_scale * factor);
  }

  // Make sure we forget about what is too close to the boundary
  params_.edge_threshold_ = std::max(params_.edge_threshold_, params_.patch_size_ + kKernelWidth / 2 + 2);

  // pre-compute the end of a row in a circular patch
  half_patch_size_ = params_.patch_size_ / 2;
  u_max_.resize(half_patch_size_ + 1);
  for (int v = 0; v <= half_patch_size_ * sqrt(2.f) / 2 + 1; ++v)
    u_max_[v] = cvRound(sqrt(float(half_patch_size_ * half_patch_size_ - v * v)));

  // Make sure we are symmetric
  for (int v = half_patch_size_, v_0 = 0; v >= half_patch_size_ * sqrt(2.f) / 2; --v)
  {
    while (u_max_[v_0] == u_max_[v_0 + 1])
      ++v_0;
    u_max_[v] = v_0;
    ++v_0;
  }
}