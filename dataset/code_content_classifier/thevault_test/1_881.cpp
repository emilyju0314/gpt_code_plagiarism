void runtime_distributed::stop_helper(
        bool blocking, std::condition_variable& cond, std::mutex& mtx)
    {
        // wait for thread manager to exit
        runtime_support_->stopped();        // re-activate shutdown HPX-thread
        thread_manager_->stop(blocking);    // wait for thread manager

        deinit_global_data();

        // this disables all logging from the main thread
        deinit_tss_helper("main-thread", 0);

        LRT_(info).format("runtime_distributed: stopped all services");

        std::lock_guard<std::mutex> l(mtx);
        cond.notify_all();    // we're done now
    }