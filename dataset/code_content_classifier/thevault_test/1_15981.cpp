void ENC28J60_EMAC::receiver_thread_function(void* params) {
    ENC28J60_EMAC *enc28j60_enet = static_cast<ENC28J60_EMAC *>(params);

    while(1) {
        uint32_t flags = ThisThread::flags_wait_any(FLAG_RX);

        if (flags & FLAG_RX) {
        	enc28j60_enet->packet_rx();
        }
        enc28j60_enet->_enc28j60->enable_interrupt(ENC28J60_INTERRUPT_ENABLE);
    }
}