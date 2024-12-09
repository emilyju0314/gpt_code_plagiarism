inline int
    init(util::function_nonser<int(int, char**)> const& f,
        std::string const& app_name, int argc, char** argv,
        hpx::runtime_mode mode)
    {
        using boost::program_options::options_description;
        options_description desc_commandline(
            std::string("Usage: ") + app_name +  " [options]");

        util::function_nonser<int(boost::program_options::variables_map& vm)>
            main_f = util::bind(detail::init_helper, util::placeholders::_1, f);
        std::vector<std::string> cfg;
        util::function_nonser<void()> const empty;

        HPX_ASSERT(argc != 0 && argv != nullptr);

        return init(main_f, desc_commandline, argc, argv, cfg,
            empty, empty, mode);
    }