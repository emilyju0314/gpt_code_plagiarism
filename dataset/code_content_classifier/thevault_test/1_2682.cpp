void gjAPI::Update()
{
    // update network object
    m_pNetwork->Update();

    if(!this->IsUserConnected()) return;

    if(m_iNextPing)
    {
        // update ping for the user session
        const time_t iCurTime = time(NULL);
        if(iCurTime >= m_iNextPing)
        {
            m_iNextPing = iCurTime + GJ_API_PING_TIME;
            this->__PingSession(m_bActive);
        }
    }
}