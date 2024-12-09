bool PathFinder::setReachableFinalStops(
        const PathSpecification& path_spec,
        std::ofstream& trace_file,
        std::map<int, int>& reachable_final_stops) const
    {
        int end_taz_id = path_spec.outbound_ ? path_spec.origin_taz_id_ : path_spec.destination_taz_id_;
        double dir_factor = path_spec.outbound_ ? 1.0 : -1.0;

        // are there any egress/access links?
        if (access_egress_links_.hasLinksForTaz(end_taz_id) == false) {
            if (path_spec.trace_) { trace_file << "No links for end_taz_id" << end_taz_id << std::endl; }
            return false;
        }

        // Are there any supply modes for this demand mode?
        UserClassPurposeMode ucpm = {
            path_spec.user_class_,
            path_spec.purpose_,
            path_spec.outbound_ ? MODE_ACCESS: MODE_EGRESS,
            path_spec.outbound_ ? path_spec.access_mode_ : path_spec.egress_mode_
        };
        WeightLookup::const_iterator iter_weights = weight_lookup_.find(ucpm);
        if (iter_weights == weight_lookup_.end()) {
            std::cerr << "Couldn't find any weights configured for user class/purpose (3) [" << path_spec.user_class_ << "/" << path_spec.purpose_ << "], ";
            std::cerr << (path_spec.outbound_ ? "access mode [" : "egress mode [");
            std::cerr << (path_spec.outbound_ ? path_spec.access_mode_ : path_spec.egress_mode_) << "] for person " << path_spec.person_id_ << " trip " << path_spec.person_trip_id_ << std::endl;
            return false;
        }

        // Iterate through valid supply modes
        SupplyModeToNamedWeights::const_iterator iter_s2w;
        for (iter_s2w  = iter_weights->second.begin();
             iter_s2w != iter_weights->second.end(); ++iter_s2w) {
            int supply_mode_num = iter_s2w->first;

            if (path_spec.trace_) {
                trace_file << "Weights exist for supply mode " << supply_mode_num << " => ";
                trace_file << mode_num_to_str_.find(supply_mode_num)->second << std::endl;
            }

            for (AccessEgressLinkAttr::const_iterator iter_aelk  = access_egress_links_.lower_bound(end_taz_id, supply_mode_num);
                                                      iter_aelk != access_egress_links_.upper_bound(end_taz_id, supply_mode_num); ++iter_aelk)
            {

                // Iterate through the links for the given supply mode
                int stop_id = iter_aelk->first.stop_id_;
                if (reachable_final_stops.count(stop_id) == 0) {
                    reachable_final_stops[stop_id] = 0;
                } else {
                    reachable_final_stops[stop_id] += 1;
                }

                if (path_spec.trace_) {
                    trace_file << "Stop " << stop_id << " reachable by supply mode " << supply_mode_num << std::endl;
                }
            }
        }

        return (reachable_final_stops.size() > 0);
    }