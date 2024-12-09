inline int
    init(boost::program_options::options_description const& desc_cmdline,
        int argc, char** argv, std::vector<std::string> const& cfg,
        hpx::runtime_mode mode)
    {
        return init(desc_cmdline, argc, argv, cfg, startup_function_type(),
            shutdown_function_type(), mode);
    }