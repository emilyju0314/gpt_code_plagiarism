bool default_counter_discoverer(counter_info const& info,
        discover_counter_func const& f,
        discover_counters_mode mode, error_code& ec)
    {
        return f(info, ec);
    }