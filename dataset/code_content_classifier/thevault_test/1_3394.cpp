void resource_manager::stop_executor(std::size_t cookie, error_code& ec)
    {
        std::lock_guard<mutex_type> l(mtx_);
        proxies_map_type::iterator it = proxies_.find(cookie);
        if (it == proxies_.end()) {
            HPX_THROWS_IF(ec, bad_parameter, "resource_manager::detach",
                "the given cookie is not known to the resource manager");
            return;
        }

        // inform executor to give up virtual cores
        proxy_data& p = (*it).second;
        for (coreids_type coreids : p.core_ids_)
        {
            p.proxy_->remove_processing_unit(coreids.second, ec);
        }
    }