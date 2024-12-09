bool list_counter(
        performance_counters::counter_info const& info, error_code& ec)
    {
        print(info.fullname_, ec);
        return true;
    }