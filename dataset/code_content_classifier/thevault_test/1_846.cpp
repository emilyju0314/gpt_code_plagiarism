void init(
        bool init_mpi, std::string const& pool_name, bool init_errorhandler)
    {
        if (init_mpi)
        {
            int required = MPI_THREAD_MULTIPLE;
            int minimal = MPI_THREAD_FUNNELED;
            int provided;
            hpx::util::mpi_environment::init(
                nullptr, nullptr, required, minimal, provided);
            if (provided < MPI_THREAD_FUNNELED)
            {
                mpi_debug.error(debug::str<>("hpx::mpi::experimental::init"),
                    "init failed");
                HPX_THROW_EXCEPTION(invalid_status,
                    "hpx::mpi::experimental::init",
                    "the MPI installation doesn't allow multiple threads");
            }
            MPI_Comm_rank(MPI_COMM_WORLD, &detail::get_mpi_info().rank_);
            MPI_Comm_size(MPI_COMM_WORLD, &detail::get_mpi_info().size_);
        }
        else
        {
            // Check if MPI_Init has been called previously
            if (detail::get_mpi_info().size_ == -1)
            {
                int is_initialized = 0;
                MPI_Initialized(&is_initialized);
                if (is_initialized)
                {
                    MPI_Comm_rank(
                        MPI_COMM_WORLD, &detail::get_mpi_info().rank_);
                    MPI_Comm_size(
                        MPI_COMM_WORLD, &detail::get_mpi_info().size_);
                }
            }
        }

        mpi_debug.debug(debug::str<>("hpx::mpi::experimental::init"),
            detail::get_mpi_info());

        if (init_errorhandler)
        {
            set_error_handler();
            detail::get_mpi_info().error_handler_initialized_ = true;
        }

        // install polling loop on requested thread pool
        if (pool_name.empty())
        {
            detail::register_polling(hpx::resource::get_thread_pool(0));
        }
        else
        {
            detail::register_polling(hpx::resource::get_thread_pool(pool_name));
        }
    }