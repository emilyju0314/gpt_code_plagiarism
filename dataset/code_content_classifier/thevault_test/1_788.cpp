void ORB::operator()(const cv::Mat &image, const cv::Mat &mask, std::vector<cv::KeyPoint> & keypoints)
{
  cv::Mat empty_descriptors;
  this->operator ()(image, mask, keypoints, empty_descriptors, true, false);
}