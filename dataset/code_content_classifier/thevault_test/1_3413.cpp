inline int
    init(int (*f)(boost::program_options::variables_map& vm),
        boost::program_options::options_description const& desc_cmdline,
        int argc, char** argv, startup_function_type startup,
        shutdown_function_type shutdown, hpx::runtime_mode mode)
    {
        std::vector<std::string> cfg;
        return init(f, desc_cmdline, argc, argv, cfg, std::move(startup),
            std::move(shutdown), mode);
    }