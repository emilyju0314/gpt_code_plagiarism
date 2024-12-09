int swServer_create_task_workers(swServer *serv)
{
    key_t key = 0;
    int ipc_mode;

    if (serv->task_ipc_mode == SW_TASK_IPC_MSGQUEUE || serv->task_ipc_mode == SW_TASK_IPC_PREEMPTIVE)
    {
        key = serv->message_queue_key;
        ipc_mode = SW_IPC_MSGQUEUE;
    }
    else if (serv->task_ipc_mode == SW_TASK_IPC_STREAM)
    {
        ipc_mode = SW_IPC_SOCKET;
    }
    else
    {
        ipc_mode = SW_IPC_UNIXSOCK;
    }

    swProcessPool *pool = &serv->gs->task_workers;
    if (swProcessPool_create(pool, serv->task_worker_num, key, ipc_mode) < 0)
    {
        swWarn("[Master] create task_workers failed");
        return SW_ERR;
    }

    swProcessPool_set_max_request(pool, serv->task_max_request, serv->task_max_request_grace);
    swProcessPool_set_start_id(pool, serv->worker_num);
    swProcessPool_set_type(pool, SW_PROCESS_TASKWORKER);

    if (ipc_mode == SW_IPC_SOCKET)
    {
        char sockfile[sizeof(struct sockaddr_un)];
        snprintf(sockfile, sizeof(sockfile), "/tmp/swoole.task.%d.sock", serv->gs->master_pid);
        if (swProcessPool_create_unix_socket(&serv->gs->task_workers, sockfile, 2048) < 0)
        {
            return SW_ERR;
        }
    }

    return SW_OK;
}