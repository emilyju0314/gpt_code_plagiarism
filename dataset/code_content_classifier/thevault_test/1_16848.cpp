void SlamMap::mapCallback(const nav_msgs::OccupancyGridConstPtr& map) {

    //ROS_INFO("Received a %d X %d map @ %.3f m/pix", map->info.width, map->info.height, map->info.resolution);

    if (saveMap_) {
        createPgmMapFile(map);
        createTxtPositionFile();
    }

    mapInterface(map);


}