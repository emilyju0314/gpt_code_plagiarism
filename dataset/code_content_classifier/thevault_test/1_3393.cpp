std::vector<std::pair<std::size_t, std::size_t> >
    resource_manager::allocate_virt_cores(
        detail::manage_executor* proxy, std::size_t min_punits,
        std::size_t max_punits, error_code& ec)
    {
        std::vector<coreids_type> core_ids;

        // array of available processing units
        std::vector<punit_status> available_punits(
            get_os_thread_count(), punit_status::unassigned);

        // find all available processing units with zero use count
        std::size_t reserved = reserve_processing_units(0, max_punits,
            available_punits);
        if (reserved < max_punits)
        {
            // insufficient available cores found, try to share
            // processing units
            preprocess_static_allocation(min_punits, max_punits);

            reserved += release_cores_on_existing_schedulers(
                release_borrowed_cores, available_punits);

            if(reserved < max_punits)
            {
                reserved += redistribute_cores_among_all(
                    reserved, min_punits, max_punits, available_punits);

                if (reserved < min_punits)
                {
                    reserved += release_cores_on_existing_schedulers(
                        release_cores_to_min, available_punits);
                    if (reserved < min_punits)
                    {
                        reserve_at_higher_use_count(
                            min_punits - reserved , available_punits);
                    }
                }
            }
        }

        // processing units found, inform scheduler
        std::size_t punit = 0;
        for (std::size_t i = 0; i != available_punits.size(); ++i)
        {
            if (available_punits[i] == punit_status::reserved) //-V104
            {
                proxy->add_processing_unit(punit, i, ec);
                if (ec) break;

                core_ids.push_back(std::make_pair(i, punit));
                ++punit;

                // update use count for reserved processing units
                ++punits_[i].use_count_;
            }
        }
        HPX_ASSERT(punit <= max_punits);

        if (ec) {
            // on error, remove the already assigned virtual cores
            for (std::size_t j = 0; j != punit; ++j)
            {
                proxy->remove_processing_unit(j, ec);
                --punits_[j].use_count_;
            }
            return std::vector<coreids_type>();
        }

        if (&ec != &throws)
            ec = make_success_code();
        return core_ids;
    }