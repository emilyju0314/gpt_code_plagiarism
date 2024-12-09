void interval_timer::schedule_thread(std::unique_lock<mutex_type> & l)
    {
        HPX_ASSERT(l.owns_lock());

        using namespace hpx::threads;

        error_code ec;

        // create a new suspended thread
        threads::thread_id_type id;
        {
            // FIXME: registering threads might lead to thread suspension since
            // the allocators use hpx::lcos::local::spinlock. Unlocking the
            // lock here would be the right thing but leads to crashes and hangs
            // at shutdown.
            //util::unlock_guard<std::unique_lock<mutex_type> > ul(l);
            id = hpx::applier::register_thread_plain(
                util::bind(&interval_timer::evaluate,
                    this->shared_from_this(), util::placeholders::_1),
                description_.c_str(), threads::suspended, true,
                threads::thread_priority_boost, std::size_t(-1),
                threads::thread_stacksize_default, ec);
        }

        if (ec) {
            is_terminated_ = true;
            is_started_ = false;
            return;
        }

        // schedule this thread to be run after the given amount of seconds
        threads::set_thread_state(id,
            std::chrono::microseconds(microsecs_),
            threads::pending, threads::wait_signaled,
            threads::thread_priority_boost, ec);

        if (ec) {
            is_terminated_ = true;
            is_started_ = false;

            // abort the newly created thread
            threads::set_thread_state(id, threads::pending, threads::wait_abort,
                threads::thread_priority_boost, ec);

            return;
        }

        id_ = id;
        is_started_ = true;
    }