err_t TcpReceive(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err) {
    EthernetTcp::TcpData *tcpClientData =
        static_cast<EthernetTcp::TcpData *>(arg);
    if (tcpClientData == nullptr) {
        return ERR_ARG;
    }
    // A NULL pbuf indicates that the remote host closed the connection.
    if (p == NULL) {
        TcpClose(tpcb, tcpClientData);
        return ERR_OK;
    }
    // If return anything other than ERR_OK or ERR_ABRT, must NOT free pbuf.
    if (err != ERR_OK) {
        return err;
    }
    if (tcpClientData->state == ESTABLISHED) {
        // Only copy the packet's payload if we have enough empty space to copy
        // every byte.
        int32_t availableToRead =
            tcpClientData->dataTail - tcpClientData->dataHead;
        if (availableToRead  < 0) {
            availableToRead += TCP_DATA_BUFFER_SIZE;
        }
        if (TCP_DATA_BUFFER_SIZE - availableToRead < p->tot_len) {
            return ERR_BUF;
        }
        // Put received packet into the buffer.
        uint16_t bytesReceived = p->tot_len;
        for (uint16_t i = 0; i < bytesReceived; i++) {
            uint16_t nextIndex = (tcpClientData->dataTail + 1) %
                                 TCP_DATA_BUFFER_SIZE;
            // If the buffer is full drop the rest
            if (nextIndex == tcpClientData->dataHead) {
                bytesReceived = i;
                break;
            }
            // If the buffer is not full, save the value
            tcpClientData->data[tcpClientData->dataTail] = pbuf_get_at(p, i);
            tcpClientData->dataTail = nextIndex;
        }
        // Acknowledge the data was received.
        tcp_recved(tcpClientData->pcb, bytesReceived);
        // Must free the pbuf
        pbuf_free(p);
        return ERR_OK;
    }
    // If we got this far, we've received a non-empty frame without error,
    // but there's no established TCP connection.
    tcp_recved(tcpClientData->pcb, p->tot_len);
    pbuf_free(p);
    return ERR_OK;
}