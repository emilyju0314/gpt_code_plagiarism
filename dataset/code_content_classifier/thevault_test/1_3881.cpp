static bool filter_msg_by_telemetry_intervals(const MsgChannel &channel)
{
    if (telemetry_timers[channel].elapsed_ms() > telemetry_intervals_ms[channel])
    {
        telemetry_timers[channel].reset();
        return true;
    }
    else
    {
        return false;
    }
}