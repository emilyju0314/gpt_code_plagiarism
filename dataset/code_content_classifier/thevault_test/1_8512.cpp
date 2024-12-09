int mg_set_protocol_coap(struct mg_connection *nc) {
    /* supports UDP only */
    if ((nc->flags & MG_F_UDP) == 0) {
        return -1;
    }

    nc->proto_handler = coap_handler;

    return 0;
}