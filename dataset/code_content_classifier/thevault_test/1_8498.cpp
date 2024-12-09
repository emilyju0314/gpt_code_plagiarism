static void mg_sock_set(struct mg_connection *nc, sock_t sock) {
    mg_set_non_blocking_mode(sock);
    mg_set_close_on_exec(sock);
    nc->sock = sock;
    DBG(("%p %d", nc, sock));
}