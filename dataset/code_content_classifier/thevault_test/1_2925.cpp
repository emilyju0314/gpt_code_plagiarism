void EthernetManager::NetifInit() {
    struct netif *netif = &m_macInterface;
    ip_addr_t dummyIp = IPADDR4_INIT(0);

    netif_add(netif, &dummyIp, &dummyIp, &dummyIp,
              &m_ethernetInterface, ethernetif_init, ethernet_input);

    netif_set_default(netif);

    netif_set_link_up(netif);

    netif_set_up(netif);

    Enable(true);
}