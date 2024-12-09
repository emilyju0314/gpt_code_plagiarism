void ORB::computeOrientation(const cv::Mat& image, const cv::Mat& integral_image, unsigned int scale,
                             std::vector<cv::KeyPoint>& keypoints) const
{
  // Process each keypoint
  for (std::vector<cv::KeyPoint>::iterator keypoint = keypoints.begin(), keypoint_end = keypoints.end(); keypoint
      != keypoint_end; ++keypoint)
  {
    //get a patch at the keypoint
    if (integral_image.empty())
    {
      switch (image.depth())
      {
        case CV_8U:
          IC_Angle<uchar, int> (image, half_patch_size_, *keypoint, u_max_);
          break;
        case CV_32S:
          IC_Angle<int, int> (image, half_patch_size_, *keypoint, u_max_);
          break;
        case CV_32F:
          IC_Angle<float, float> (image, half_patch_size_, *keypoint, u_max_);
          break;
        case CV_64F:
          IC_Angle<double, double> (image, half_patch_size_, *keypoint, u_max_);
          break;
      }
    }
    else
    {
      // use the integral image if you can
      switch (integral_image.depth())
      {
        case CV_32S:
          IC_Angle_Integral<int> (integral_image, half_patch_size_, *keypoint, orientation_horizontal_offsets_[scale],
                                  orientation_vertical_offsets_[scale]);
          break;
        case CV_32F:
          IC_Angle_Integral<float> (integral_image, half_patch_size_, *keypoint,
                                    orientation_horizontal_offsets_[scale], orientation_vertical_offsets_[scale]);
          break;
        case CV_64F:
          IC_Angle_Integral<double> (integral_image, half_patch_size_, *keypoint,
                                     orientation_horizontal_offsets_[scale], orientation_vertical_offsets_[scale]);
          break;
      }
    }
  }
}