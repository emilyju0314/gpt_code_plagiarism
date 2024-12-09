void walker::laserScanCallback(const sensor_msgs::LaserScan::ConstPtr &range) {
  for (auto i = 0; i < range->ranges.size(); ++i) {
    if (range->ranges[i] < 0.3) {
      obstacleRange = true;
      return;
    }
  }
  obstacleRange = false;
  return;
}