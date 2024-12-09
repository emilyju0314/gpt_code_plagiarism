inline int
    init(std::string const& app_name, int argc, char** argv,
        hpx::runtime_mode mode)
    {
        return init(static_cast<hpx_main_type>(::hpx_main), app_name,
            argc, argv, startup_function_type(), shutdown_function_type(),
            mode);
    }