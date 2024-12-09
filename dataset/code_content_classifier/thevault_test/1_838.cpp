inline int init(std::function<int(int, char**)> f, int argc, char** argv,
        init_params const& params)
    {
        std::function<int(hpx::program_options::variables_map&)> main_f =
            util::bind_back(detail::init_helper, std::move(f));
        return detail::init_impl(std::move(main_f), argc, argv, params);
    }