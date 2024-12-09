void simple_cache::handle_response (int port, Mem_req *mreq)
{
    assert(m_IS_LAST_LEVEL);

    #ifdef DBG_SIMPLE_CACHE
    cout << "@@@ " << Manifold::NowTicks() << " simple cache " << m_node_id << " " << m_name << ": handle_response from memory, " << *mreq << endl;
    #endif

    if(mreq->op_type == OpMemSt) //write response is ignored
        return;

    my_table->process_response (mreq->addr);

    free_mshr_entries(mreq->addr);

    delete mreq; //delete the Mem_req

}