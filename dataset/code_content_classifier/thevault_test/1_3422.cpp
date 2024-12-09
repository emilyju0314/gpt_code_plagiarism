inline int init(int (*f)(boost::program_options::variables_map&),
        int argc, char** argv, hpx::runtime_mode mode)
    {
        std::string app_name(HPX_APPLICATION_STRING);
        return init(f, app_name, argc, argv, mode);
    }