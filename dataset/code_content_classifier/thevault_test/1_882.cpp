void stop_evaluating_counters(bool terminate)
    {
        runtime_distributed* rtd = get_runtime_distributed_ptr();
        if (nullptr != rtd)
            rtd->stop_evaluating_counters(terminate);
    }