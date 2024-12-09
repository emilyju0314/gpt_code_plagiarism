static void resolve_cb(struct mg_dns_message *msg, void *data) {
    struct mg_connection *nc = (struct mg_connection *) data;
    int i;
    int failure = -1;

    if (msg != NULL) {
        /*
         * Take the first DNS A answer and run...
         */
        for (i = 0; i < msg->num_answers; i++) {
            if (msg->answers[i].rtype == MG_DNS_A_RECORD) {
                /*
                 * Async resolver guarantees that there is at least one answer.
                 * TODO(lsm): handle IPv6 answers too
                 */
                mg_dns_parse_record_data(msg, &msg->answers[i], &nc->sa.sin.sin_addr,
                                         4);
                mg_do_connect(nc, nc->flags & MG_F_UDP ? SOCK_DGRAM : SOCK_STREAM,
                              &nc->sa);
                return;
            }
        }
    }

    /*
     * If we get there was no MG_DNS_A_RECORD in the answer
     */
    mg_call(nc, NULL, MG_EV_CONNECT, &failure);
    mg_call(nc, NULL, MG_EV_CLOSE, NULL);
    mg_destroy_conn(nc);
}