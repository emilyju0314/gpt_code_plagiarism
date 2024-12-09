bool runtime::unregister_thread()
    {
        deinit_tss_helper(
            detail::thread_name().c_str(), hpx::get_worker_thread_num());
        return true;
    }