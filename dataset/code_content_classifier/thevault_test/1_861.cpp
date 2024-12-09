void measure_action_futures_wait_all(std::uint64_t count, bool csv)
{
    const hpx::naming::id_type here = hpx::find_here();
    std::vector<future<double>> futures;
    futures.reserve(count);

    // start the clock
    high_resolution_timer walltime;
    for (std::uint64_t i = 0; i < count; ++i)
        futures.push_back(async<null_action>(here));
    wait_all(futures);

    // stop the clock
    const double duration = walltime.elapsed();
    print_stats("action", "WaitAll", "no-executor", count, duration, csv);
}