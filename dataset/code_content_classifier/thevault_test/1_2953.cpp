err_t TcpAccept(void *arg, struct tcp_pcb *newpcb, err_t err) {
    EthernetTcp::TcpData **tcpClientData = (EthernetTcp::TcpData **)arg;

    // Set the priority for the new TCP connection. Make this higher than min?
    tcp_setprio(newpcb, TCP_PRIO_MIN);

    if ((tcpClientData == nullptr) || (err != ERR_OK)) {
        // Either the client PCBs could not be allocated or there was another
        // error that occurred during TCP connection setup.
        tcp_close(newpcb);
        return ERR_ARG;
    }

    EthernetTcp::TcpData *clientData =
        (EthernetTcp::TcpData *)calloc(1, sizeof(EthernetTcp::TcpData));
    if (clientData == nullptr) {
        TcpClose(newpcb, clientData);
        return ERR_MEM;
    }

    clientData->pcb = newpcb;
    clientData->state = ESTABLISHED;

    bool accepted = false;

    // Look for an open 'socket' to allow the client to connect to the server.
    for (uint8_t iClient = 0; iClient < CLIENT_MAX; iClient++) {
        if (tcpClientData[iClient] == nullptr) {
            tcpClientData[iClient] = clientData;
            accepted = true;
            break;
        }
    }

    if (!accepted) {
        TcpClose(newpcb, clientData);
        free(clientData);
        return ERR_MEM;
    }
    tcp_nagle_disable(newpcb);

    tcp_arg(newpcb, clientData);
    tcp_recv(newpcb, TcpReceive);
    tcp_err(newpcb, TcpError);
    tcp_sent(newpcb, TcpSend);

    return ERR_OK;
}