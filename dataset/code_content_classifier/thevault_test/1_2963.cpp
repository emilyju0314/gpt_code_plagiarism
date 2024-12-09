void SerialBase::PortOpen() {
    if (!m_portOpen) {
        m_portOpen = true;
        PortMode(m_portMode);
    }
}