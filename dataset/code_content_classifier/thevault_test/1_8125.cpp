void OnPointCloudAvailable(void* /*context*/,
                           const TangoPointCloud* point_cloud) {
  // Number of points in the point cloud.
  float average_depth;

  // Calculate the average depth.
  average_depth = 0;
  // Each xyzc point has 4 coordinates.
  for (size_t i = 0; i < point_cloud->num_points; ++i) {
    average_depth += point_cloud->points[i][2];
  }
  if (point_cloud->num_points) {
    average_depth /= point_cloud->num_points;
  }

  // Log the number of points and average depth.
  LOGI("HelloDepthPerceptionApp: Point count: %d. Average depth (m): %.3f",
       point_cloud->num_points, average_depth);
}