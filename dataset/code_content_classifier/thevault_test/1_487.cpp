void PathFinder::updateStopStatesForTransfers(
        const PathSpecification& path_spec,
        std::ofstream& trace_file,
        StopStates& stop_states,
        LabelStopQueue& label_stop_queue,
        int label_iteration,
        const LabelStop& current_label_stop) const
    {
        double dir_factor = path_spec.outbound_ ? 1.0 : -1.0;

        // current_stop_state is a hyperlink
        // It should have trip-states in it, because otherwise it wouldn't have come up in the label stop queue to process
        Hyperlink& current_stop_state  = stop_states[current_label_stop.stop_id_];
        double current_deparr_time     = current_stop_state.latestDepartureEarliestArrival(true);
        double nonwalk_label           = current_stop_state.hyperpathCost(true);

        // Lookup transfer weights
        // TODO: returning here is probably terrible and we shouldn't be silent... We should have zero weights if we don't want to penalize.
        const NamedWeights* transfer_weights = getNamedWeights(path_spec.user_class_, path_spec.purpose_, MODE_TRANSFER, "transfer", transfer_supply_mode_);
        if (transfer_weights == NULL) { return; }

        // add zero-walk transfer to this stop
        int               xfer_stop_id  = current_label_stop.stop_id_;
        const Attributes* zerowalk_xfer = getTransferAttributes(xfer_stop_id, xfer_stop_id);
        double            transfer_time = zerowalk_xfer->find("walk_time_min")->second;  // todo: make this a different time?
        double            deparr_time   = current_deparr_time - (transfer_time*dir_factor);
        double            link_cost, cost, transfer_dist;
        if (path_spec.hyperpath_)
        {
            link_cost = tallyLinkCost(transfer_supply_mode_, path_spec, trace_file, *transfer_weights, *zerowalk_xfer);
            cost      = nonwalk_label + link_cost;
        } else {
            link_cost = transfer_time;
            cost      = current_label_stop.label_ + link_cost;
        }
        // addStopState will handle logic of updating total cost
        StopState ss(
            deparr_time,                    // departure/arrival time
            MODE_TRANSFER,                  // departure/arrival mode
            1 ,                             // trip id
            current_label_stop.stop_id_,    // successor/predecessor
            -1,                             // sequence
            -1,                             // sequence succ/pred
            transfer_time,                  // link time
            0.0,                            // link fare
            link_cost,                      // link cost
            0.0,                            // link distance
            cost,                           // cost
            label_iteration,                // label iteration
            current_deparr_time,            // arrival/departure time
      0.0                             // link ivt weight
        );
        addStopState(path_spec, trace_file, xfer_stop_id, ss, &current_stop_state, stop_states, label_stop_queue);

        // are there other relevant transfers?
        // if outbound, going backwards, so transfer TO this current stop
        // if inbound, going forwards, so transfer FROM this current stop
        const StopStopToAttr&          transfer_links  = (path_spec.outbound_ ? transfer_links_d_o_ : transfer_links_o_d_);
        StopStopToAttr::const_iterator transfer_map_it = transfer_links.find(current_label_stop.stop_id_);
        bool                           found_transfers = (transfer_map_it != transfer_links.end());

        if (!found_transfers) { return; }

        for (StopToAttr::const_iterator transfer_it = transfer_map_it->second.begin();
             transfer_it != transfer_map_it->second.end(); ++transfer_it)
        {
            xfer_stop_id    = transfer_it->first;
            transfer_time   = transfer_it->second.find("time_min")->second;
            transfer_dist   = transfer_it->second.find("dist")->second;
            // outbound: departure time = latest departure - transfer
            //  inbound: arrival time   = earliest arrival + transfer
            deparr_time     = current_deparr_time - (transfer_time*dir_factor);

            // stochastic/hyperpath: cost update
            if (path_spec.hyperpath_)
            {
                Attributes link_attr            = transfer_it->second;
                link_attr["transfer_penalty"]   = 1.0; // TODO: make configurable or base off of IVT coefficient
                link_cost                       = tallyLinkCost(transfer_supply_mode_, path_spec, trace_file, *transfer_weights, link_attr);
                cost                            = nonwalk_label + link_cost;
            }
            // deterministic: label = cost = total time, just additive
            else
            {
                link_cost           = transfer_time;
                cost                = current_label_stop.label_ + link_cost;

                // check (departure mode, stop) if someone's waiting already
                // curious... this only applies to OUTBOUND
                // TODO: capacity stuff
                if (path_spec.outbound_)
                {
                    int current_trip = current_stop_state.lowestCostStopState(true).trip_id_;
                    TripStop ts = { current_trip, current_stop_state.lowestCostStopState(true).seq_, current_label_stop.stop_id_ };
                    std::map<TripStop, double, struct TripStopCompare>::const_iterator bwi = bump_wait_.find(ts);
                    if (bwi != bump_wait_.end())
                    {
                        // time a bumped passenger started waiting
                        double latest_time = bwi->second;
                        // we can't come in time
                        if (deparr_time - Hyperlink::TIME_WINDOW_ > latest_time) { continue; }
                        // leave earlier -- to get in line 5 minutes before bump wait time
                        // (confused... We don't resimulate previous bumping passenger so why does this make sense?)
                        cost            = cost + (current_stop_state.lowestCostStopState(true).deparr_time_ - latest_time) + BUMP_BUFFER_;
                        deparr_time     = latest_time - transfer_time - BUMP_BUFFER_;
                    }
                }
            }

            // addStopState will handle logic of updating total cost
            StopState ss(
                deparr_time,                    // departure/arrival time
                MODE_TRANSFER,                  // departure/arrival mode
                1 ,                             // trip id
                current_label_stop.stop_id_,    // successor/predecessor
                -1,                             // sequence
                -1,                             // sequence succ/pred
                transfer_time,                  // link time
                0.0,                            // link fare
                link_cost,                      // link cost
                transfer_dist,                  // link distance
                cost,                           // cost
                label_iteration,                // label iteration
                current_deparr_time,            // arrival/departure time
        0.0                             // link ivt weight
            );
            addStopState(path_spec, trace_file, xfer_stop_id, ss, &current_stop_state, stop_states, label_stop_queue);
        }
    }