bool per_action_data_counter_discoverer(counter_info const& info,
        discover_counter_func const& f, discover_counters_mode mode,
        hpx::parcelset::detail::per_action_data_counter_registry& registry,
        error_code& ec)
    {
        // compose the counter name templates
        performance_counters::counter_path_elements p;
        performance_counters::counter_status status =
            get_counter_path_elements(info.fullname_, p, ec);
        if (!status_is_valid(status)) return false;

        bool result = registry.counter_discoverer(info, p, f, mode, ec);
        if (!result || ec) return false;

        if (&ec != &throws)
            ec = make_success_code();

        return true;
    }