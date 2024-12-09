void SlamMap::mapMetadataCallback(const nav_msgs::MapMetaDataConstPtr &metadata) {

    ROS_INFO("Received MapMetadata Origin Position!");

    origin_pos_x_ = metadata->origin.position.x;
    origin_pos_y_ = metadata->origin.position.y;
    origin_pos_z_ = metadata->origin.position.z;

    origin_or_x_ = metadata->origin.orientation.x;
    origin_or_y_ = metadata->origin.orientation.y;
    origin_or_z_ = metadata->origin.orientation.z;
    origin_or_w_ = metadata->origin.orientation.w;

    mapWidth_ = metadata->width;
    mapHeight_ = metadata->height;
    mapResolution_ = metadata->resolution;

    mapInitData_ = true;

}