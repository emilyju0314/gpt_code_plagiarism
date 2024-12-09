void default_executor::add(closure_type&& f,
        util::thread_description const& desc,
        threads::thread_state_enum initial_state,
        bool run_now, threads::thread_stacksize stacksize, error_code& ec)
    {
        if (stacksize == threads::thread_stacksize_default)
            stacksize = stacksize_;

        register_thread_nullary(std::move(f), desc, initial_state, run_now,
            priority_, os_thread_, stacksize, ec);
    }