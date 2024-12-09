void UdpReceive(void *arg, struct udp_pcb *pcb, struct pbuf *p,
                const ip_addr_t *addr, u16_t port) {
    EthernetUdp::UdpData *data = (EthernetUdp::UdpData *)arg;

    // Bail out if the udp_pcb received could not be allocated
    // or if we received to an unregistered udp_pcb.
    if (data == nullptr || data->pcb != pcb) {
        pbuf_free(p);
        return;
    }

    // Drop the last packet received.
    if (data->packet != nullptr) {
        pbuf_free(data->packet);
    }

    // Copy the remote IP, port, packet contents and number of bytes received
    // into the UDP state.
    ip_addr_copy(data->remoteIp, *addr);
    data->remotePort = port;
    data->packet = p;
    data->available = p->tot_len;
}