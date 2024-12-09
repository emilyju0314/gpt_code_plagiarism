bool EthernetManager::ReceivedFrameFlag() {
    bool recv = m_recv;
    m_recv = false;
    return recv;
}