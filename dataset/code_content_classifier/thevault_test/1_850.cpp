inline bool start(
        std::nullptr_t, int argc, char** argv, init_params const& params)
    {
        util::function_nonser<int(hpx::program_options::variables_map&)> main_f;
        return detail::start_impl(std::move(main_f), argc, argv, params);
    }