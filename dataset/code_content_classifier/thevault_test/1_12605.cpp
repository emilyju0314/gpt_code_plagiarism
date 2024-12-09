void simple_cache::handle_cache_response (int port, Cache_req *request)
{
    assert(m_IS_LAST_LEVEL == false);

    #ifdef DBG_SIMPLE_CACHE
    cout << "@@@ " << Manifold::NowTicks() << " simple cache " << m_node_id << " " << m_name << ": handle_response from upper level cache, " << *request << endl;
    #endif

    assert(request->op_type == OpMemLd);


    my_table->process_response (request->addr);

    free_mshr_entries(request->addr);

    delete request;
}