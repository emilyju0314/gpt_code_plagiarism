inline int init(init_params const& params)
    {
        util::function_nonser<int(hpx::program_options::variables_map&)>
            main_f = static_cast<hpx_main_type>(::hpx_main);
        return detail::init_impl(
            std::move(main_f), detail::dummy_argc, detail::dummy_argv, params);
    }