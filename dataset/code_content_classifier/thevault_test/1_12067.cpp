void TimeViewPlugin::SetCurrentTime(double timeInSeconds)
    {
        const double oneMs = 1.0 / 1000.0;
        if (!AZ::IsClose(m_curTime, timeInSeconds, oneMs))
        {
            m_dirty = true;
        }
        m_curTime = timeInSeconds;
    }