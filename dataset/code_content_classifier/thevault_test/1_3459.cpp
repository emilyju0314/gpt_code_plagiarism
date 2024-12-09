void console_error_sink(boost::exception_ptr const& e)
    {
        if (HPX_UNLIKELY(!threads::get_self_ptr()))
            HPX_THROW_EXCEPTION(null_thread_id
              , "components::console_error_sink"
              , "console_error_sink was not called from a HPX-thread");

        // retrieve console locality
        naming::gid_type console_gid;
        naming::get_agas_client().get_console_locality(console_gid);
        naming::id_type dst(console_gid, naming::id_type::unmanaged);

        // Report the error only if the thread-manager is up.
        if (threads::threadmanager_is(state_running))
        {
            hpx::async<server::console_error_sink_action>(dst, e).get();
        }
    }