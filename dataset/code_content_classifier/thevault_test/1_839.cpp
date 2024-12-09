inline int init(int argc, char** argv, init_params const& params)
    {
        std::function<int(hpx::program_options::variables_map&)> main_f =
            static_cast<hpx_main_type>(::hpx_main);
        return detail::init_impl(std::move(main_f), argc, argv, params);
    }