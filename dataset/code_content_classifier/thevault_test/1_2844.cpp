std::vector<pcl::PointCloud<pcl::PointXYZRGB>> CameraConnector::retrievePointClouds()
{
    float s = connectedCams.size();
    std::vector<pcl::PointCloud<pcl::PointXYZRGB>> pointclouds;
    std::tuple<pcl::PointCloud<pcl::PointXYZRGB>, double> cloudStamp;
    for(int i = 0; i<s ; i++) {
        cloudStamp = connectedCams.at(i)->getLatestPointCloudRGB();
        pointclouds.push_back(std::get<0>(cloudStamp));
    }
    CameraConnector::lastTimeStamp = std::get<1>(cloudStamp);
    return pointclouds;
}