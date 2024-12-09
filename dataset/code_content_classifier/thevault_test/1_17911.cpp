int swServer_add_systemd_socket(swServer *serv)
{
    char *e = getenv("LISTEN_PID");
    if (!e)
    {
        return 0;
    }

    int pid = atoi(e);
    if (getpid() != pid)
    {
        swWarn("invalid LISTEN_PID");
        return 0;
    }

    int n = swoole_get_systemd_listen_fds();
    if (n == 0)
    {
        return 0;
    }

    int count = 0;
    int sock;

    for (sock = SW_SYSTEMD_FDS_START; sock < SW_SYSTEMD_FDS_START + n; sock++)
    {
        swListenPort *ls = (swListenPort *) SwooleG.memory_pool->alloc(SwooleG.memory_pool, sizeof(swListenPort));
        if (ls == NULL)
        {
            swWarn("alloc failed");
            return count;
        }

        if (swPort_set_address(ls, sock) < 0)
        {
            return count;
        }
        ls->host[SW_HOST_MAXSIZE - 1] = 0;

        //O_NONBLOCK & O_CLOEXEC
        swoole_fcntl_set_option(sock, 1, 1);
        ls->socket = swSocket_new(sock, swSocket_is_dgram(ls->type) ? SW_FD_DGRAM_SERVER : SW_FD_STREAM_SERVER);
        if (ls->socket == nullptr)
        {
            close(sock);
            return count;
        }
        swServer_check_port_type(serv, ls);

        serv->listen_list->push_back(ls);
        serv->listen_port_num++;
        count++;
    }
    return count;
}