void SandTimer::startOver()
{
    start_time_ = millis();
    if (!started_)
        started_ = true;
}