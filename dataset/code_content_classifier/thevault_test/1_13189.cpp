EventOverlay* OverlayDataSvc::getRootEventOverlay()
{
    if (m_needToReadEvent && m_configureForInput) selectNextEvent();

    return m_eventOverlay;
}