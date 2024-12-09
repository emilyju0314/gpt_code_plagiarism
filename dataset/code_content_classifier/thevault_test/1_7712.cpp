inline void dump_timers() {
    decltype(auto) timers = get_timers().timers;

    //Sort the timers by duration (DESC)
    std::sort(timers.begin(), timers.end(), [](auto& left, auto& right) {
        return left.duration > right.duration;
    });

    // Print all the used timers
    for (decltype(auto) timer : timers) {
        if (timer.name) {
            size_t count = timer.count;
            size_t duration = timer.duration;
            std::cout << timer.name << "(" << count << ") : "
                      << duration_str(duration)
                      << " (" << duration_str(duration / count) << ")" << std::endl;
        }
    }
}