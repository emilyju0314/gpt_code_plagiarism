void bind_to_core(cpu_set_t mask)
{
    if (sched_setaffinity(0, sizeof(mask), &mask) != 0)
        logstream(LOG_ERROR) << "Fail to set affinity!" << LOG_endl;
}