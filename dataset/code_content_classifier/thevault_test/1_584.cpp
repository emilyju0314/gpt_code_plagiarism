bool SandTimer::finished()
{
    if (started_)
    {
        end_time_ = millis();
        const Real elaspedTime = end_time_ - start_time_;
//        fprintf(stderr, "start: %f, end: %f, elapsed: %f, period: %f\n", start_time_, end_time_, elaspedTime, period_);
        if (elaspedTime >= period_)
        {
            started_ = false;
        }
    }
    return !started_;
}