void ORB::computeIntegralImage(const cv::Mat & image, unsigned int level, cv::Mat &integral_image)
{
  integral(image, integral_image, CV_32S);
  integral_image_steps_.resize(params_.n_levels_, 0);

  unsigned int integral_image_step = integral_image.step1();
  if (integral_image_steps_[level] == integral_image_step)
    return;

  // If the integral image dimensions have changed, recompute everything

  // Cache the step sizes
  integral_image_steps_[level] = integral_image_step;

  // Cache the offsets for the orientation
  orientation_horizontal_offsets_.resize(params_.n_levels_);
  orientation_vertical_offsets_.resize(params_.n_levels_);
  orientation_horizontal_offsets_[level].resize(8 * half_patch_size_);
  orientation_vertical_offsets_[level].resize(8 * half_patch_size_);
  for (int v = 1, offset_index = 0; v <= half_patch_size_; ++v)
  {
    // Compute the offsets to use if using the integral image
    for (int signed_v = -v; signed_v <= v; signed_v += 2 * v)
    {
      // the offsets are computed so that we can compute the integral image
      // elem at 0 - eleme at 1 - elem at 2 + elem at 3
      orientation_horizontal_offsets_[level][offset_index] = (signed_v + 1) * integral_image_step + u_max_[v] + 1;
      orientation_vertical_offsets_[level][offset_index] = (u_max_[v] + 1) * integral_image_step + signed_v + 1;
      ++offset_index;
      orientation_horizontal_offsets_[level][offset_index] = signed_v * integral_image_step + u_max_[v] + 1;
      orientation_vertical_offsets_[level][offset_index] = -u_max_[v] * integral_image_step + signed_v + 1;
      ++offset_index;
      orientation_horizontal_offsets_[level][offset_index] = (signed_v + 1) * integral_image_step - u_max_[v];
      orientation_vertical_offsets_[level][offset_index] = (u_max_[v] + 1) * integral_image_step + signed_v;
      ++offset_index;
      orientation_horizontal_offsets_[level][offset_index] = signed_v * integral_image_step - u_max_[v];
      orientation_vertical_offsets_[level][offset_index] = -u_max_[v] * integral_image_step + signed_v;
      ++offset_index;
    }
  }

  // Remove the previous version if dimensions are different
  patterns_.resize(params_.n_levels_, 0);
  if (patterns_[level])
    delete patterns_[level];

  patterns_[level] = new OrbPatterns(params_.patch_size_, integral_image_step);
}