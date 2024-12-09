void resource_manager::preprocess_static_allocation(
        std::size_t min_punits, std::size_t max_punits)
    {
        proxies_map_type::iterator it;
        proxies_static_allocation_data.clear();

        for (proxies_map_type::iterator it = proxies_.begin();
             it != proxies_.end(); ++it)
        {
            proxy_data& p = (*it).second;
            static_allocation_data st;
            st.proxy_ = p.proxy_;

            // ask executor for its policies
            error_code ec1(lightweight);
            st.min_proxy_cores_ =
                p.proxy_->get_policy_element(detail::min_concurrency, ec1);
            if (ec1) st.min_proxy_cores_ = 1;
            st.max_proxy_cores_ =
                p.proxy_->get_policy_element(detail::max_concurrency, ec1);
            if (ec1) st.max_proxy_cores_ = get_os_thread_count();

            st.num_borrowed_cores_ = 0;
            st.num_owned_cores_ = 0;

            for (coreids_type coreids : p.core_ids_)
            {
                if (punits_[coreids.first].use_count_ > 1)
                    st.num_borrowed_cores_++;
                if (punits_[coreids.first].use_count_ == 1)
                    st.num_owned_cores_++;
            }

            proxies_static_allocation_data.insert(
                allocation_data_map_type::value_type((*it).first , st));
        }

        std::size_t cookie = next_cookie_ + 1;

        static_allocation_data st;
        st.min_proxy_cores_ = min_punits;
        st.max_proxy_cores_ = max_punits;
        st.adjusted_desired_ = static_cast<double>(max_punits);
        st.num_cores_stolen_ = 0;
        proxies_static_allocation_data.insert(
            allocation_data_map_type::value_type(cookie , st));
    }