void bind_to_all()
{
    cpu_set_t mask;
    CPU_ZERO(&mask);
    for (int i = 0; i < default_bindings.size(); i++)
        CPU_SET(default_bindings[i], &mask);

    if (sched_setaffinity(0, sizeof(mask), &mask) != 0)
        logstream(LOG_ERROR) << "Fail to set affinity" << LOG_endl;
}