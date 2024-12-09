inline double throughput(uint64_t bytes, double seconds)
{
    if (seconds == 0.0)
        return 0.0;
    return static_cast<double>(bytes) / (1024 * 1024) / seconds;
}