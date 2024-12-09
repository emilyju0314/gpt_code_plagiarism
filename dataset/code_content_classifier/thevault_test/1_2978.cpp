int32_t SerialBase::AvailableForWrite() {
    int32_t difference = m_outHead - m_outTail - 1;

    if (difference < 0) {
        difference += SERIAL_BUFFER_SIZE;
    }

    return difference;
}