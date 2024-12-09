int16_t SerialBase::CharPeek() {
    // Return if nothing is waiting
    if (m_inTail == m_inHead) {
        return SerialBase::EOB;
    }

    // Get head character
    int16_t peekChar = m_bufferIn[m_inHead];
    return (peekChar);
}