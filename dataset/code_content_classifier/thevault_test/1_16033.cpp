void DriveTrainSubsystemBase::ForwardInSeconds(double goalTime, double speed)
{
    m_autoTimer.Stop();
    m_autoTimer.Reset();
    m_autoTimer.Start();
    units::second_t startTime = m_autoTimer.Get();
    do
    {
        Forward(speed);
    } while (goalTime > (double)m_autoTimer.Get()-(double)startTime);
    Stop();
}