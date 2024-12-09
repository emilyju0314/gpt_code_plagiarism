inline int init(std::vector<std::string> const& cfg,
        hpx::runtime_mode mode)
    {
        using boost::program_options::options_description;

        options_description desc_commandline(
            std::string("Usage: ") + HPX_APPLICATION_STRING +  " [options]");

        char *dummy_argv[2] = { const_cast<char*>(HPX_APPLICATION_STRING), nullptr };

        return init(static_cast<hpx_main_type>(::hpx_main), desc_commandline,
            1, dummy_argv, cfg, startup_function_type(),
            shutdown_function_type(), mode);
    }