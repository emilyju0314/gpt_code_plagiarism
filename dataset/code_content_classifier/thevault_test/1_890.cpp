bool runtime::register_thread(char const* name,
        std::size_t global_thread_num, bool service_thread, error_code& ec)
    {
        std::string thread_name(name);
        thread_name += "-thread";

        init_tss_ex(thread_name.c_str(),
            runtime_local::os_thread_type::custom_thread, global_thread_num,
            global_thread_num, "", nullptr, service_thread, ec);

        return !ec ? true : false;
    }