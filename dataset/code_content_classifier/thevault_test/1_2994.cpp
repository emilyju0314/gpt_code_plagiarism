void UsbManager::TxPump() {
    if (atomic_test_and_set_acqrel(&m_sendActive)) {
        // Already sending; can't send anything more right now
        return;
    }

    uint32_t head = m_outHead;
    uint32_t tail = m_outTail;
    if (head == tail) {
        // Nothing to send, bail out
        atomic_clear_seqcst(&m_sendActive);
        return;
    }

    // The data sent to cdcdf_acm_write needs to be 4-byte aligned,
    // so copy the data into an aligned buffer before sending it out
    uint32_t count = sizeof(m_usbWriteBuf);
    uint8_t *inPtr = m_bufferOut + head, *outPtr = m_usbWriteBuf;
    if (head < tail) {
        count = min(count, tail - head);
        for (uint32_t iChar = 0; iChar < count; iChar++) {
            *outPtr++ = *inPtr++;
        }
    }
    else {
        uint32_t countTilWrap = sizeof(m_bufferOut) - head;
        count = min(count, countTilWrap + tail);
        uint32_t loopEnd = min(countTilWrap, count);
        for (uint32_t iChar = 0; iChar < loopEnd; iChar++) {
            *outPtr++ = *inPtr++;
        }
        inPtr = m_bufferOut;
        loopEnd = count - loopEnd;
        for (uint32_t iChar = 0; iChar < loopEnd; iChar++) {
            *outPtr++ = *inPtr++;
        }
    }
    if (cdcdf_acm_write(m_usbWriteBuf, count)) {
        // cdcdf_acm_write failed, clear the send active flag
        atomic_clear_seqcst(&m_sendActive);
    }
}