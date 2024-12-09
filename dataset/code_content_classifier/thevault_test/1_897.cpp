std::string trace_on_new_stack(
        std::size_t frames_no = HPX_HAVE_THREAD_BACKTRACE_DEPTH)
    {
#if defined(HPX_HAVE_STACKTRACES)
        if (frames_no == 0)
        {
            return std::string();
        }

        backtrace bt(frames_no);

        // avoid infinite recursion on handling errors
        auto* self = threads::get_self_ptr();
        if (nullptr == self ||
            self->get_thread_id() == threads::invalid_thread_id)
        {
            return bt.trace();
        }

        lcos::local::futures_factory<std::string()> p(
            [&bt]() { return bt.trace(); });

        error_code ec(lightweight);
        threads::thread_id_ref_type tid =
            p.apply("hpx::util::trace_on_new_stack",
                launch::fork_policy(threads::thread_priority::default_,
                    threads::thread_stacksize::medium),
                ec);
        if (ec)
            return "<couldn't retrieve stack backtrace>";

        // make sure this thread is executed last
        hpx::this_thread::yield_to(thread::id(tid));

        return p.get_future().get(ec);
#else
        return "";
#endif
    }