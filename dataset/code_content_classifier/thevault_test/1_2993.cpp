int32_t UsbManager::AvailableForWrite() {
    int32_t difference = m_outHead - m_outTail - 1;

    if (difference < 0) {
        difference += sizeof(m_bufferOut);
    }

    return difference;
}