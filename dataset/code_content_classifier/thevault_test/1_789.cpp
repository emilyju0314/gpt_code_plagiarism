inline void cull(std::vector<cv::KeyPoint>& keypoints, size_t n_points)
{
  //this is only necessary if the keypoints size is greater than the number of desired points.
  if (keypoints.size() > n_points)
  {
    if (n_points==0) {
      keypoints.clear();
      return;
    }
    //first use nth element to partition the keypoints into the best and worst.
    std::nth_element(keypoints.begin(), keypoints.begin() + n_points, keypoints.end(), keypointResponseGreater);
    //this is the boundary response, and in the case of FAST may be ambigous
    float ambiguous_response = keypoints[n_points - 1].response;
    //use std::partition to grab all of the keypoints with the boundary response.
    std::vector<cv::KeyPoint>::const_iterator new_end =
        std::partition(keypoints.begin() + n_points, keypoints.end(),
                       KeypointResponseGreaterThanEqual(ambiguous_response));
    //resize the keypoints, given this new end point. nth_element and partition reordered the points inplace
    keypoints.resize(new_end - keypoints.begin());
  }
}