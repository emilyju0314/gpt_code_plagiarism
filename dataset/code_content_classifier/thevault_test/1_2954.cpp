void TcpError(void *arg, err_t err) {
    EthernetTcp::TcpData *data = (EthernetTcp::TcpData *)arg;

    if ((data == nullptr) || (err == ERR_OK)) {
        return;
    }

    // At this point the TCP PCB is already free'd.
    data->pcb = nullptr;
    data->state = CLOSING;
}