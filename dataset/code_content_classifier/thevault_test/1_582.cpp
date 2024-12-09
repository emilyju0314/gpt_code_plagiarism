void SandTimer::start(millis_time_t period)
{
    if (!started_)
    {
        // calibrating “period”
        setPeriod(period * PERIOD_RATIO);
        start_time_ = millis();
        started_ = true;
    }
}