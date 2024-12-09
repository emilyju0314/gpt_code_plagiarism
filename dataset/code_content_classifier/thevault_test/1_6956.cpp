void DiffusionProb::SendNegReinf()
{
    ns_addr_t bcast_addr;
    bcast_addr.addr_ = MAC_BROADCAST;
    bcast_addr.port_ = ROUTING_PORT;

    Packet *pkt = prepare_message(0, bcast_addr, NEG_REINFORCE);
    MACprepare(pkt, MAC_BROADCAST, NS_AF_ILINK, 0);
    MACsend(pkt, 0);
    overhead++;
    return;
}