void resource_manager::detach(std::size_t cookie, error_code& ec)
    {
        std::lock_guard<mutex_type> l(mtx_);
        proxies_map_type::iterator it = proxies_.find(cookie);
        if (it == proxies_.end()) {
            HPX_THROWS_IF(ec, bad_parameter, "resource_manager::detach",
                "the given cookie is not known to the resource manager");
            return;
        }

        // adjust resource usage count
        proxy_data& p = (*it).second;
        for (coreids_type coreids : p.core_ids_)
        {
            HPX_ASSERT(punits_[coreids.first].use_count_ != 0);
            --punits_[coreids.first].use_count_;
        }

        proxies_.erase(cookie);
    }