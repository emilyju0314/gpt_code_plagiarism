int swServer_create_pipe_buffers(swServer *serv)
{
    serv->pipe_buffers = (swPipeBuffer **) sw_calloc(serv->reactor_num, sizeof(swPipeBuffer *));
    if (serv->pipe_buffers == NULL)
    {
        swSysError("malloc[buffers] failed");
        return SW_ERR;
    }
    for (uint32_t i = 0; i < serv->reactor_num; i++)
    {
        serv->pipe_buffers[i] = (swPipeBuffer *) sw_malloc(serv->ipc_max_size);
        if (serv->pipe_buffers[i] == NULL)
        {
            swSysError("malloc[sndbuf][%d] failed", i);
            return SW_ERR;
        }
        bzero(serv->pipe_buffers[i], sizeof(swDataHead));
    }

    return SW_OK;
}