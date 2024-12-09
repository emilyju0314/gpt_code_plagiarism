std::size_t runtime_configuration::get_thread_pool_size(
        char const* poolname) const
    {
        if (util::section const* sec = get_section("hpx.threadpools");
            nullptr != sec)
        {
            return hpx::util::get_entry_as<std::size_t>(
                *sec, std::string(poolname) + "_size", 2);
        }
        return 2;    // the default size for all pools is 2
    }