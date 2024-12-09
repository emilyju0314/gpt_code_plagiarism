inline int init(std::function<int(hpx::program_options::variables_map&)> f,
        int argc, char** argv, init_params const& params)
    {
        return detail::init_impl(std::move(f), argc, argv, params);
    }