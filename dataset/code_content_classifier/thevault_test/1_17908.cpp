int swServer_create_user_workers(swServer *serv)
{
    /**
     * if Swoole\Server::addProcess is called first, 
     * swServer::user_worker_list is initialized in the swServer_add_worker function
     */
    if (serv->user_worker_list == nullptr)
    {
        serv->user_worker_list = new std::vector<swWorker *>;
    }

    serv->user_workers = (swWorker *) SwooleG.memory_pool->alloc(SwooleG.memory_pool, serv->user_worker_num * sizeof(swWorker));
    if (serv->user_workers == NULL)
    {
        swSysWarn("gmalloc[server->user_workers] failed");
        return SW_ERR;
    }
    return SW_OK;
}