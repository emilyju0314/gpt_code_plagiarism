bool resource_manager::release_scheduler_resources(
        allocation_data_map_type::iterator it, std::size_t number_to_free,
        std::vector<punit_status>& available_punits)
    {
        static_allocation_data st;
        std::size_t borrowed_cores;
        std::size_t owned_cores;

        st = (*it).second;

        proxies_map_type::iterator iter;
        iter = proxies_.find((*it).first);
        // FIXME: handle iter == proxies.end()

        proxy_data& p = (*iter).second;

        if (number_to_free == release_borrowed_cores)
        {
            number_to_free = borrowed_cores = st.num_borrowed_cores_;
        }
        else if (number_to_free == release_cores_to_min)
        {
            // number_to_free includes all
            number_to_free = st.num_owned_cores_ - st.min_proxy_cores_ -
                (st.num_cores_stolen_ - st.num_borrowed_cores_);
            borrowed_cores = 0;
        }
        else
        {
            borrowed_cores = 0;
        }

        // owned_cores number of cores can be released only
        owned_cores = number_to_free - borrowed_cores;

        if (number_to_free > 0)
        {
            for (coreids_type coreids : p.core_ids_) {
                // check all cores
                if (punits_[coreids.first].use_count_ > 0 || owned_cores > 0)
                {
                    // The proxy remembers this processor as gone ..
                    // TODO

                    // increase number of stolen cores
                    ++(*it).second.num_cores_stolen_;

                    // reduce use_count as core is released
                    --punits_[coreids.first].use_count_;

                    if (punits_[coreids.first].use_count_ > 0)
                    {
                        --owned_cores;
                    }

                    if (--number_to_free == 0)
                    {
                        return true;
                    }
                }
            }
        }

        // The scheduler proxy does not have any cores available to free.
        return false;
    }