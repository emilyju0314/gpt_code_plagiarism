std::size_t resource_manager::redistribute_cores_among_all(
        std::size_t reserved, std::size_t min_punits, std::size_t max_punits,
        std::vector<punit_status>& available_punits)
    {
        std::size_t available = 0;

        // Try to proportionally allocate cores to all schedulers w/o
        // oversubscription. The proportions used will be max_punits for each
        // scheduler, except that no existing scheduler will be forced to
        // increase the current allocation.
        if (proxies_static_allocation_data.size() > 1)
        {
            std::size_t total_minimum = min_punits;
            std::size_t total_allocated = reserved;
            // sum of cores that have been previously reserved and cores that
            // were reserved during this allocation attempt.
            std::size_t num_schedulers = 1; // includes the current scheduler

            // total_allocated is the number of cores allocated to new
            // scheduler so far plus the number of 'owned' cores allocated to
            // all existing schedulers.
            allocation_data_map_type::iterator end =
                proxies_static_allocation_data.end();
            --end;

            for (allocation_data_map_type::iterator it =
                    proxies_static_allocation_data.begin();
                 it != end; ++it)
            {
                static_allocation_data st = (*it).second;

                if (st.num_owned_cores_ > st.min_proxy_cores_)
                {
                    ++num_schedulers;
                    total_minimum += st.min_proxy_cores_;
                    total_allocated += st.num_owned_cores_;
                }
            }

            if (num_schedulers > 1 && total_minimum <= total_allocated)
            {
                // We have found schedulers with cores greater than min.
                // Moreover, the sum of all cores already allocated to
                // existing schedulers can at least satisfy all mins
                // (including the min requirement of the current scheduler).
                double total_desired = 0.0;
                double scaling = 0.0;

                allocation_data_map_type scaled_static_allocation_data;

                allocation_data_map_type::iterator inner_end =
                    proxies_static_allocation_data.end();
                --inner_end;

                for (allocation_data_map_type::iterator it =
                        proxies_static_allocation_data.begin();
                     it != proxies_static_allocation_data.end(); ++it)
                {
                    static_allocation_data st = (*it).second;
                    if (st.num_owned_cores_ > st.min_proxy_cores_ || it == inner_end)
                    {
                        st.adjusted_desired_ =
                            static_cast<double>(st.max_proxy_cores_);
                        scaled_static_allocation_data.insert(
                            allocation_data_map_type::value_type((*it).first, st));

                        total_desired += st.adjusted_desired_;
                    }
                }

                while (true)
                {
                    // scaling factor
                    scaling = double(total_allocated) / total_desired;

                    for (allocation_data_map_type::iterator it =
                            scaled_static_allocation_data.begin();
                         it != scaled_static_allocation_data.end(); ++it)
                    {
                        static_allocation_data st = (*it).second;
                        st.scaled_allocation_ = st.adjusted_desired_ * scaling;
                    }

                    roundup_scaled_allocations(scaled_static_allocation_data,
                        total_allocated);

                    bool re_calculate = false;
                    allocation_data_map_type::iterator iter =
                        scaled_static_allocation_data.end();
                    --iter;

                    for (allocation_data_map_type::iterator it =
                            scaled_static_allocation_data.begin();
                         it != iter; ++it)
                    {
                        static_allocation_data st = (*it).second;

                        if (st.allocation_ > st.num_owned_cores_)
                        {
                            double modifier = static_cast<double>(
                                st.num_owned_cores_ / st.allocation_);

                            // Reduce adjusted_desired by multiplying it with
                            // 'modifier', to try to bias allocation to the
                            // original size or less.
                            total_desired -= st.adjusted_desired_ * (1.0 - modifier);
                            st.adjusted_desired_ = modifier * st.adjusted_desired_;

                            re_calculate = true;
                        }
                    }

                    if (re_calculate)
                    {
                        continue;
                    }

                    for (allocation_data_map_type::iterator it =
                            scaled_static_allocation_data.begin();
                         it != scaled_static_allocation_data.end(); ++it)
                    {
                        // Keep recursing until all allocations are no greater
                        // than desired (including the current scheduler).
                        static_allocation_data st = (*it).second;

                        if (st.allocation_ > st.min_proxy_cores_)
                        {
                            double modifier = static_cast<double>(
                                st.min_proxy_cores_ / st.allocation_);

                            // Reduce adjusted_desired by multiplying with it
                            // 'modifier', to try to bias allocation to desired
                            // or less.
                            total_desired -= st.adjusted_desired_ * (1.0 - modifier);
                            st.adjusted_desired_ = modifier*st.adjusted_desired_;
                            re_calculate = true;
                        }
                    }

                    if (re_calculate)
                    {
                        continue;
                    }

                    for (allocation_data_map_type::iterator it =
                            scaled_static_allocation_data.begin();
                         it != scaled_static_allocation_data.end(); ++it)
                    {
                        // Keep recursing until all allocations are at least
                        // minimum (including the current scheduler).
                        static_allocation_data st = (*it).second;

                        if (st.min_proxy_cores_ > st.allocation_)
                        {
                            double new_desired =
                                double(st.min_proxy_cores_) / scaling;

                            // Bias desired to get allocation closer to min.
                            total_desired += new_desired - st.adjusted_desired_;
                            st.adjusted_desired_ = new_desired;

                            re_calculate = true;
                        }
                    }

                    if (re_calculate)
                    {
                        continue;
                    }
                    break;
                } // end of while(true)

                allocation_data_map_type::iterator it =
                    scaled_static_allocation_data.end();
                HPX_ASSERT(it != scaled_static_allocation_data.begin());
                static_allocation_data st = (*--it).second;

                if (st.allocation_ > total_allocated)
                {
                    allocation_data_map_type::iterator iter =
                        scaled_static_allocation_data.end();
                    --iter;

                    for (allocation_data_map_type::iterator it =
                            scaled_static_allocation_data.begin();
                         it != iter; ++it)
                    {
                        static_allocation_data st = (*it).second;

                        std::size_t reduce_by = st.num_owned_cores_ - st.allocation_;
                        if (reduce_by > 0)
                        {
                            release_scheduler_resources(it, reduce_by, available_punits);
                        }
                    }

                    // Reserve out of the cores we just freed.
                    available = reserve_processing_units(0,
                        st.allocation_ - reserved, available_punits);
                }

                scaled_static_allocation_data.clear();
            }
        }
        return available;
    }