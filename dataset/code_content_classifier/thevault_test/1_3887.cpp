static void update_telemetry_intervals(unsigned long int nn_interval_ms)
{
    if (update_telemetry_interval_cb == nullptr)
    {
        util::log_info("Attempting to update telemetry intervals before a callback function is set.");
        return;
    }

    (*update_telemetry_interval_cb)(nn_interval_ms);
}