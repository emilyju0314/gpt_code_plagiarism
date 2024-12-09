int32_t UsbManager::AvailableForRead() {
    int32_t difference = m_inTail - m_inHead;

    if (difference < 0) {
        return sizeof(m_bufferIn) + difference;
    }
    else {
        return difference;
    }
}