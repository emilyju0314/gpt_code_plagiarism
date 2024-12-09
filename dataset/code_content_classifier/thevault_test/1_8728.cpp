void bind_to_core(size_t core)
{
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(core, &mask);
    if (sched_setaffinity(0, sizeof(mask), &mask) != 0)
        logstream(LOG_ERROR) << "Failed to set affinity (core: " << core << ")" << LOG_endl;
}