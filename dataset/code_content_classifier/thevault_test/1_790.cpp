void ORB::computeKeyPoints(const std::vector<cv::Mat>& image_pyramid, const std::vector<cv::Mat>& mask_pyramid,
                           std::vector<std::vector<cv::KeyPoint> >& all_keypoints_out) const
{
  all_keypoints_out.resize(params_.n_levels_);

  // half_patch_size_ for orientation, 4 for Harris
  unsigned int edge_threshold = std::max(std::max(half_patch_size_, 4), params_.edge_threshold_);

  for (unsigned int level = 0; level < params_.n_levels_; ++level)
  {
    all_keypoints_out[level].reserve(n_features_per_level_[level]);

    std::vector<cv::KeyPoint> & keypoints = all_keypoints_out[level];

    // Detect FAST features, 20 is a good threshold
    cv::FastFeatureDetector fd(20, true);
    fd.detect(image_pyramid[level], keypoints, mask_pyramid[level]);

    // Remove keypoints very close to the border
    cv::KeyPointsFilter::runByImageBorder(keypoints, image_pyramid[level].size(), edge_threshold);

    // Keep more points than necessary as FAST does not give amazing corners
    cull(keypoints, 2 * n_features_per_level_[level]);

    // Compute the Harris cornerness (better scoring than FAST)
    HarrisResponse h(image_pyramid[level]);
    h(keypoints);
    //cull to the final desired level, using the new Harris scores.
    cull(keypoints, n_features_per_level_[level]);

    // Set the level of the coordinates
    for (std::vector<cv::KeyPoint>::iterator keypoint = keypoints.begin(), keypoint_end = keypoints.end(); keypoint
        != keypoint_end; ++keypoint)
      keypoint->octave = level;
  }
}