int16_t SerialBase::CharGet() {
    // Return if nothing is waiting.
    if (m_inTail == m_inHead) {
        return SerialBase::EOB;
    }

    // Get head of buffer, wrapped.
    int32_t nextIndex = NextIndex(m_inHead);
    // Get head character.
    int16_t returnChar = m_bufferIn[m_inHead];
    // Save new head ptr.
    m_inHead = nextIndex;
    EnableRxcInterruptUart();

    return returnChar;
}