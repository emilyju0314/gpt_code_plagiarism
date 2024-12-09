std::size_t resource_manager::release_cores_on_existing_schedulers(
        std::size_t number_to_free,
        std::vector<punit_status>& available_punits)
    {
        // Ask previously allocated schedulers to release surplus cores,
        // until either the request is satisfied, or we're out of
        // schedulers.
        bool released_cores = false;
        allocation_data_map_type::iterator end =
            proxies_static_allocation_data.end();
        --end;

        for (allocation_data_map_type::iterator it =
                proxies_static_allocation_data.begin();
             it != end; ++it)
        {
            // check each scheduler
            if (release_scheduler_resources(it, number_to_free, available_punits))
            {
                released_cores = true;
            }
        }

        std::size_t available = 0;
        if (released_cores)
        {
            available = reserve_processing_units(0, number_to_free, available_punits);
            // reserve resources if available
        }

        return available;
    }