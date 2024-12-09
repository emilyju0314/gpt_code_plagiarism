static void *per_connection_thread_function(void *param) {
    struct mg_connection *c = (struct mg_connection *) param;
    struct mg_mgr m;

    mg_mgr_init(&m, NULL);
    mg_add_conn(&m, c);
    while (m.active_connections != NULL) {
        mg_mgr_poll(&m, 1000);
    }
    mg_mgr_free(&m);

    return param;
}