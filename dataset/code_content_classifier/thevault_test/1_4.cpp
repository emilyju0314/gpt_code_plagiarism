void processPointcloud(
    pcl::PointCloud<pcl::PointXYZI>& final_cloud,
    const std::vector<pcl::PointCloud<pcl::PointXYZ>>& complete_cloud,
    Box histogram_box, const FOV_indices& FOV, const Eigen::Vector3f& position,
    float min_realsense_dist, int max_age, float elapsed_s) {
  pcl::PointCloud<pcl::PointXYZI> old_cloud;
  std::swap(final_cloud, old_cloud);
  final_cloud.points.clear();
  final_cloud.width = 0;
  final_cloud.points.reserve((2 * GRID_LENGTH_Z) * (2 * GRID_LENGTH_E));

  float distance;

  // double resolution histogram for subsampling
  // the distance layer will show whether the cell is already
  // occupied by a point
  Histogram high_res_histogram = Histogram(ALPHA_RES / 2);

  for (const auto& cloud : complete_cloud) {
    for (const pcl::PointXYZ& xyz : cloud) {
      // Check if the point is invalid
      if (!std::isnan(xyz.x) && !std::isnan(xyz.y) && !std::isnan(xyz.z)) {
        if (histogram_box.isPointWithinBox(xyz.x, xyz.y, xyz.z)) {
          distance = (position - toEigen(xyz)).norm();
          if (distance > min_realsense_dist &&
              distance < histogram_box.radius_) {
            // subsampling the cloud
            PolarPoint p_pol = cartesianToPolar(toEigen(xyz), position);
            Eigen::Vector2i p_ind = polarToHistogramIndex(p_pol, ALPHA_RES / 2);
            if (high_res_histogram.get_dist(p_ind.y(), p_ind.x()) == 0) {
              final_cloud.points.push_back(toXYZI(toEigen(xyz), 0));
              high_res_histogram.set_dist(p_ind.y(), p_ind.x(), 1);
            }
          }
        }
      }
    }
  }

  // combine with old cloud
  for (const pcl::PointXYZI& xyzi : old_cloud) {
    // adding older points if not expired and space is free according to new
    // cloud
    if (histogram_box.isPointWithinBox(xyzi.x, xyzi.y, xyzi.z)) {
      distance = (position - toEigen(xyzi)).norm();
      if (distance < histogram_box.radius_) {
        PolarPoint p_pol = cartesianToPolar(toEigen(xyzi), position);
        Eigen::Vector2i p_ind = polarToHistogramIndex(p_pol, ALPHA_RES / 2);
        if (high_res_histogram.get_dist(p_ind.y(), p_ind.x()) == 0 &&
            xyzi.intensity < max_age && !pointInsideFOV(FOV, p_pol)) {
          final_cloud.points.push_back(
              toXYZI(toEigen(xyzi), xyzi.intensity + elapsed_s));
          high_res_histogram.set_dist(p_ind.y(), p_ind.x(), 1);
        }
      }
    }
  }

  final_cloud.header.stamp = complete_cloud[0].header.stamp;
  final_cloud.header.frame_id = complete_cloud[0].header.frame_id;
  final_cloud.height = 1;
  final_cloud.width = final_cloud.points.size();
}