void SlamMap::mapInterface(const nav_msgs::OccupancyGridConstPtr& map) {

    /*
    for (std::vector<int>::size_type i = 0; i != map->data.size() ; i++) {
        printf("%d ", map->data[i]);
    }*/ //data -1, 0-100

    mapData_.resize(map->data.size());

    for (unsigned int y = 0; y < map->info.height; y++) {
        for (unsigned int x = 0; x < map->info.width; x++) {
             unsigned int i = x + (map->info.height - y - 1) * map->info.width;

            if (map->data[i] >= 0 && map->data[i] <= threshold_free_) {

                //fputc(254, out);
                mapData_[i] = 254;

            } else if (map->data[i] >= threshold_occupied_) {

                //fputc(000, out);
                mapData_[i] = 0;

            } else {

                //fputc(205, out);
                mapData_[i] = 205;

            }
        }
    }
}