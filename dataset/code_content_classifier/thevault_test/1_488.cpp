void PathFinder::updateStopStatesForFinalLinks(
        const PathSpecification& path_spec,
        std::ofstream& trace_file,
        const std::map<int, int>& reachable_final_stops,
        StopStates& stop_states,
        LabelStopQueue& label_stop_queue,
        int label_iteration,
        const LabelStop& current_label_stop,
        double& est_max_path_cost) const
    {
        // shortcut -- nothing to do if this isn't reachable to end taz
        if (reachable_final_stops.count(current_label_stop.stop_id_) == 0) {
            return;
        }

        // current_stop_state is a hyperlink
        // It should have trip-states in it, because otherwise it wouldn't have come up in the label stop queue to process
        Hyperlink& current_stop_state  = stop_states[current_label_stop.stop_id_];
        double current_deparr_time     = current_stop_state.latestDepartureEarliestArrival(true);
        double nonwalk_label           = current_stop_state.hyperpathCost(true);

        int    end_taz_id = path_spec.outbound_ ? path_spec.origin_taz_id_ : path_spec.destination_taz_id_;
        double dir_factor = path_spec.outbound_ ? 1.0 : -1.0;

        double earliest_dep_latest_arr = PathFinder::MAX_DATETIME;
        if (path_spec.hyperpath_) {
            earliest_dep_latest_arr = current_stop_state.earliestDepartureLatestArrival(path_spec.outbound_, true);
        } else {
            earliest_dep_latest_arr = current_stop_state.lowestCostStopState(true).deparr_time_;
        }
        double earliest_dep_latest_arr_024 = fix_time_range(earliest_dep_latest_arr);


        // are there any egress/access links?
        if (access_egress_links_.hasLinksForTaz(end_taz_id) == false) {
            // this shouldn't happen because of the shortcut
            return;
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
            // this shouldn't happen because of the shortcut
            std::cerr << "Couldn't find any weights configured for user class/purpose (2) [" << path_spec.user_class_ << "/" << path_spec.purpose_ << "], ";
            std::cerr << (path_spec.outbound_ ? "access mode [" : "egress mode [");
            std::cerr << (path_spec.outbound_ ? path_spec.access_mode_ : path_spec.egress_mode_) << "] for person " << path_spec.person_id_ << " trip " << path_spec.person_trip_id_ << std::endl;
            return;
        }

        // Iterate through valid supply modes
        SupplyModeToNamedWeights::const_iterator iter_s2w;
        for (iter_s2w  = iter_weights->second.begin();
             iter_s2w != iter_weights->second.end(); ++iter_s2w) {
            int supply_mode_num = iter_s2w->first;

            for (AccessEgressLinkAttr::const_iterator iter_aelk  = access_egress_links_.lower_bound(end_taz_id, supply_mode_num, current_label_stop.stop_id_);
                                                      iter_aelk != access_egress_links_.upper_bound(end_taz_id, supply_mode_num, current_label_stop.stop_id_); ++iter_aelk)
            {

                const AccessEgressLinkKey& aelk = iter_aelk->first;

                // require earliest_dep_latest_arr in [start_time_, end_time)
                if (aelk.start_time_ >  earliest_dep_latest_arr_024) continue;
                if (aelk.end_time_   <= earliest_dep_latest_arr_024) continue;

                Attributes link_attr            = iter_aelk->second;
                link_attr["depart_late_min"]    = 0;
                link_attr["arrive_early_min"]   = 0;
                link_attr["depart_early_min"]   = 0.0;
                link_attr["arrive_late_min"]    = 0.0;

                double  access_time             = link_attr.find("time_min")->second;
                double  access_dist             = link_attr.find("dist")->second;
                double  deparr_time, link_cost, cost;

                if (path_spec.hyperpath_)
                {
                    deparr_time     = earliest_dep_latest_arr - (access_time*dir_factor);

                    link_cost       = tallyLinkCost(supply_mode_num, path_spec, trace_file, iter_s2w->second, link_attr);
                    cost            = nonwalk_label + link_cost;

                }
                // deterministic
                else
                {
                    deparr_time = earliest_dep_latest_arr - (access_time*dir_factor);
                    link_cost   = access_time;
                    cost        = current_stop_state.lowestCostStopState(true).cost_ + link_cost;

                    // capacity check
                    if (path_spec.outbound_)
                    {
                        TripStop ts = { current_stop_state.lowestCostStopState(true).deparr_mode_, current_stop_state.lowestCostStopState(true).seq_, current_label_stop.stop_id_ };
                        std::map<TripStop, double, struct TripStopCompare>::const_iterator bwi = bump_wait_.find(ts);
                        if (bwi != bump_wait_.end()) {
                            // time a bumped passenger started waiting
                            double latest_time = bwi->second;
                            // we can't come in time
                            if (deparr_time - Hyperlink::TIME_WINDOW_ > latest_time) { continue; }
                            // leave earlier -- to get in line 5 minutes before bump wait time
                            cost   = cost + (current_stop_state.lowestCostStopState(true).deparr_time_ - latest_time) + BUMP_BUFFER_;
                            deparr_time = latest_time - access_time - BUMP_BUFFER_;
                        }
                    }

                }

                StopState ts(
                    deparr_time,                                                                // departure/arrival time
                    path_spec.outbound_ ? MODE_ACCESS : MODE_EGRESS,                            // departure/arrival mode
                    supply_mode_num,                                                            // trip id
                    current_label_stop.stop_id_,                                                // successor/predecessor
                    -1,                                                                         // sequence
                    -1,                                                                         // sequence succ/pred
                    access_time,                                                                // link time
                    0.0,                                                                        // link fare
                    link_cost,                                                                  // link cost
                    access_dist,                                                                // link distance
                    cost,                                                                       // cost
                    label_iteration,                                                            // label iteration
                    earliest_dep_latest_arr,                                                    // arrival/departure time
          0.0                                                                         // link ivt weight
                );
                addStopState(path_spec, trace_file, end_taz_id, ts, &current_stop_state, stop_states, label_stop_queue);

                // set label_cutoff
                double low_cost = stop_states[end_taz_id].hyperpathCost(false);
                // estimate of the max path cost that would have probability > MIN_PATH_PROBABILITY

                double max_cost = low_cost - (log(MIN_PATH_PROBABILITY_) - log(1.0-MIN_PATH_PROBABILITY_))*Hyperlink::STOCH_DISPERSION_;
                est_max_path_cost = std::min(est_max_path_cost, max_cost);

            } // end iteration through links for the given supply mode
        } // end iteration through valid supply modes
     }