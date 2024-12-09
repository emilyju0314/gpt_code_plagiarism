static CTxMemPool* GetMemPool(HTTPRequest* req)
{
    if (!g_rpc_node || !g_rpc_node->mempool) {
        RESTERR(req, HTTP_NOT_FOUND, "Mempool disabled or instance not found");
        return nullptr;
    }
    return g_rpc_node->mempool;
}