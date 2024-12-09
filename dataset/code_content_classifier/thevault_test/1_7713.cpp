inline void dump_timers_one() {
    decltype(auto) timers = get_timers().timers;

    if(timers.empty()){
        return;
    }

    //Sort the timers by duration (DESC)
    std::sort(timers.begin(), timers.end(), [](auto& left, auto& right) {
        return left.duration > right.duration;
    });

    double total_duration = timers.front().duration.load();

    // Print all the used timers
    for (decltype(auto) timer : timers) {
        if (timer.name) {
            size_t count = timer.count;
            size_t duration = timer.duration;
            std::cout << timer.name << "(" << count << ") : "
                      << duration_str(duration)
                      << " (" << 100.0 * (duration / total_duration) << "%, " << duration_str(duration / count) << ")" << std::endl;
        }
    }
}