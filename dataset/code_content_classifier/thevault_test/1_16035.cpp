void LoaderSubsystemC418::Periodic()
{
#ifndef NOHW
    Util::Log("Load Photogate", m_photogate.Get());
    if (m_photogate.Get())
    {
        m_spike.TurnSpikeOn();
    }
    else
    {
        m_spike.TurnSpikeOff();
    }
#endif
}