inline int init(int (*f)(boost::program_options::variables_map&),
        std::string const& app_name, int argc, char** argv,
        hpx::runtime_mode mode)
    {
        using boost::program_options::options_description;

        options_description desc_commandline(
            "Usage: " + app_name +  " [options]");

        if (argc == 0 || argv == nullptr)
        {
            char *dummy_argv[2] = { const_cast<char*>(app_name.c_str()), nullptr };
            return init(desc_commandline, 1, dummy_argv, mode);
        }

        return init(f, desc_commandline, argc, argv, startup_function_type(),
            shutdown_function_type(), mode);
    }