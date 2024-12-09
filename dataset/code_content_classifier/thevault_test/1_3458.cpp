void console_error_sink(naming::id_type const& dst,
        boost::exception_ptr const& e)
    {
        // Report the error only if the thread-manager is up.
        if (threads::threadmanager_is(state_running))
        {
            if (threads::get_self_ptr())
            {
                hpx::async<server::console_error_sink_action>(dst, e).get();
            }
            else
            {
                // FIXME: This should use a sync_put_parcel.
                hpx::apply<server::console_error_sink_action>(dst, e);
            }
        }
    }