hpx::threads::policies::detail::polling_status poll()
    {
        using hpx::threads::policies::detail::polling_status;

        std::unique_lock<detail::mutex_type> lk(
            detail::get_vector_mtx(), std::try_to_lock);
        if (!lk.owns_lock())
        {
            if (mpi_debug.is_enabled())
            {
                // for debugging, create a timer
                static auto poll_deb =
                    mpi_debug.make_timer(1, debug::str<>("Poll - lock failed"));
                // output mpi debug info every N seconds
                mpi_debug.timed(poll_deb, detail::get_mpi_info());
            }
            return polling_status::idle;
        }

        if (mpi_debug.is_enabled())
        {
            // for debugging, create a timer
            static auto poll_deb =
                mpi_debug.make_timer(1, debug::str<>("Poll - lock success"));
            // output mpi debug info every N seconds
            mpi_debug.timed(poll_deb, detail::get_mpi_info());
        }

        // have any requests been made that need to be handled?
        // create a future data shared state
        detail::future_data_ptr val;
        while (detail::get_request_queue().try_dequeue(val))
        {
            --(detail::get_mpi_info().request_queue_size_);
            add_to_request_vector(std::move(val));
        }

        bool keep_trying = !detail::get_active_requests().empty();
        while (keep_trying)
        {
            int index = 0;
            int flag = false;
            MPI_Status status;

            int result = MPI_Testany(
                static_cast<int>(detail::get_active_requests().size()),
                &detail::get_active_requests()[0], &index, &flag, &status);

            if (result == MPI_SUCCESS)
            {
                if (mpi_debug.is_enabled())
                {
                    static auto poll_deb =
                        mpi_debug.make_timer(1, debug::str<>("Poll - success"));

                    // clang-format off
                    mpi_debug.timed(poll_deb,
                        detail::get_mpi_info(),
                        debug::str<>("Success"),
                        "index", debug::dec<>(index == MPI_UNDEFINED ? -1 : index),
                        "flag", debug::dec<>(flag),
                        "status", debug::hex(status.MPI_ERROR));
                    // clang-format on
                }

                if (index == MPI_UNDEFINED)
                    break;

                keep_trying = flag;
                if (keep_trying)
                {
                    auto req =
                        detail::get_active_requests()[std::size_t(index)];

                    mpi_debug.debug(debug::str<>("MPI_Testany(set)"),
                        detail::get_mpi_info(), "request", debug::hex<8>(req),
                        "vector size",
                        debug::dec<3>(detail::get_active_futures().size()),
                        "non null",
                        debug::dec<3>(detail::get_number_of_active_requests()));

                    // mark the future as ready by setting the shared_state
                    detail::get_active_futures()[std::size_t(index)]->set_data(
                        MPI_SUCCESS);

                    // remove the request from our vector to prevent retesting
                    detail::get_active_requests()[std::size_t(index)] =
                        MPI_REQUEST_NULL;

                    detail::get_active_futures()[std::size_t(index)] = nullptr;
                }
            }
            else
            {
                keep_trying = false;

                if (mpi_debug.is_enabled())
                {
                    auto poll_deb =
                        mpi_debug.make_timer(1, debug::str<>("Poll - <ERR>"));

                    // clang-format off
                    mpi_debug.error(poll_deb,
                        detail::get_mpi_info(),
                        debug::str<>("Poll <ERR>"),
                        "MPI_ERROR", detail::error_message(status.MPI_ERROR),
                        "status", debug::dec<>(status.MPI_ERROR),
                        "index", debug::dec<>(index),
                        "flag", debug::dec<>(flag));
                    // clang-format on
                }
            }
        }

        // if there are more than 25% NULL request handles in our vector,
        // compact them
        if (!detail::get_active_futures().empty())
        {
            std::size_t nulls =
                std::count(detail::get_active_requests().begin(),
                    detail::get_active_requests().end(), MPI_REQUEST_NULL);

            if (nulls > detail::get_active_requests().size() / 4)
            {
                // compact away any requests that have been replaced by
                // MPI_REQUEST_NULL
                auto end1 = std::remove(detail::get_active_requests().begin(),
                    detail::get_active_requests().end(), MPI_REQUEST_NULL);
                detail::get_active_requests().resize(
                    std::distance(detail::get_active_requests().begin(), end1));

                // compact away any null pointers in futures vector
                auto end2 = std::remove(detail::get_active_futures().begin(),
                    detail::get_active_futures().end(), nullptr);
                detail::get_active_futures().resize(
                    std::distance(detail::get_active_futures().begin(), end2));

                if (detail::get_active_requests().size() !=
                    detail::get_active_futures().size())
                {
                    HPX_THROW_EXCEPTION(invalid_status,
                        "hpx::mpi::experimental::poll",
                        "Fatal Error: Mismatch in vectors");
                }

                detail::get_mpi_info().active_futures_size_ =
                    detail::get_active_futures().size();

                mpi_debug.debug(debug::str<>("MPI_REQUEST_NULL"),
                    detail::get_mpi_info(), "nulls ", debug::dec<>(nulls));
            }
        }

        return detail::get_active_futures().empty() ? polling_status::idle :
                                                      polling_status::busy;
    }