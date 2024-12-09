void VisualUtilityEstimator::GetLocationsForEvaluation(
  const Mat& image,
  int minX, int minY,
  int strideX, int strideY,
  double width, double height,
  const Mat& mask,
  Mat& scores,
  PointScores* locations) {
  ROS_ASSERT(mask.empty() || mask.type() == CV_8U);
  ROS_ASSERT(scores.type() == CV_64F);
  ROS_ASSERT(locations);
  locations->clear();

  for (int i = 0, curX = minX; curX < image.cols-width; ++i) {
    for (int j = 0, curY = minY; curY < image.rows-height; ++j) {
      if (mask.empty() || mask.at<uint8_t>(i,j)) {
        locations->push_back(pair<double*, Point>(scores.ptr<double>(i,j),
                                                  Point(curX,curY)));
      }
      curY += strideY;
    }
    curX += strideX;
  }
}