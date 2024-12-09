err_t TcpSend(void *arg, struct tcp_pcb *tpcb, u16_t len) {
    (void)len;
    EthernetTcp::TcpData *data = (EthernetTcp::TcpData *)arg;

    // Either the TCP PCB couldn't be allocated or the PCB target is wrong.
    if (data == nullptr || data->pcb != tpcb) {
        return ERR_ARG;
    }
    return ERR_OK;
}