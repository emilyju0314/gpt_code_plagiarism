inline bool start(
        std::function<int(hpx::program_options::variables_map&)> f, int argc,
        char** argv, init_params const& params)
    {
        return detail::start_impl(std::move(f), argc, argv, params);
    }