int32_t SerialBase::AvailableForRead() {
    int32_t difference = m_inTail - m_inHead;

    if (difference < 0) {
        return SERIAL_BUFFER_SIZE + difference;
    }
    else {
        return difference;
    }
}