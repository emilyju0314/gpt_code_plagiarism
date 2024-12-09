counter_status install_counter_type(std::string const& name,
        counter_type type, std::string const& helptext,
        create_counter_func const& create_counter,
        discover_counters_func const& discover_counters,
        std::uint32_t version, std::string const& uom, error_code& ec)
    {
        counter_info info(type, name, helptext,
            version ? version : HPX_PERFORMANCE_COUNTER_V1, uom);
        std::shared_ptr<manage_counter_type> p =
            std::make_shared<manage_counter_type>(info);

        // Install the counter type.
        p->install(create_counter, discover_counters, ec);

        // Register the shutdown function which will clean up this counter type.
        get_runtime().add_shutdown_function(
            util::bind(&counter_type_shutdown, p));
        return status_valid_data;
    }