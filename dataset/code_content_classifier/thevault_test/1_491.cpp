const FarePeriod* PathFinder::getFarePeriod(int route_id, int board_stop_id, int alight_stop_id, double trip_depart_time) const
    {
        int board_stop_zone  = stop_num_to_stop_.find(board_stop_id)->second.zone_num_;
        int alight_stop_zone = stop_num_to_stop_.find(alight_stop_id)->second.zone_num_;
        RouteStopZone rsz;

        for (int search_type = 0; search_type < 4; ++search_type) {
            // search for route + origin zone, dest zone
            if (search_type == 0) {
                if (board_stop_zone  < 0) { continue; }
                if (alight_stop_zone < 0) { continue; }
                rsz.route_id_         = route_id;
                rsz.origin_zone_      = board_stop_zone;
                rsz.destination_zone_ = alight_stop_zone;
            } else if (search_type == 1) {
                // search for route only
                rsz.route_id_         = route_id;
                rsz.origin_zone_      = -1;
                rsz.destination_zone_ = -1;
            } else if (search_type == 2) {
                if (board_stop_zone  < 0) { continue; }
                if (alight_stop_zone < 0) { continue; }
                // search for origin zone, dest zone
                rsz.route_id_         = -1;
                rsz.origin_zone_      = board_stop_zone;
                rsz.destination_zone_ = alight_stop_zone;
            } else if (search_type == 3) {
                // search for general fare
                rsz.route_id_         = -1;
                rsz.origin_zone_      = -1;
                rsz.destination_zone_ = -1;
            }

            // find the right fare period
            std::pair<FarePeriodMmap::const_iterator, FarePeriodMmap::const_iterator> iter_range = fare_periods_.equal_range(rsz);
            FarePeriodMmap::const_iterator fp_iter = iter_range.first;
            while (fp_iter != iter_range.second) {
                if ((trip_depart_time >= fp_iter->second.start_time_) && (trip_depart_time < fp_iter->second.end_time_)) {
                    return &(fp_iter->second);
                }
                ++fp_iter;
            }
        }
        return (const FarePeriod*)0;
    }