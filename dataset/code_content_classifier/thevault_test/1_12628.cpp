void L2_cache :: m_evict_notify(ManagerInterface* manager)
{
    DBG_L2_CACHE(cout,  "    m_evict_notify\n");

    Coh_msg* req = mcp_stalled_req[manager->getManagerID()];
    assert(req);
    DBG_L2_CACHE(cout, "    There is a request waiting for eviction to finish, req= " << req << " src= " << req->src_id << " msg= " << req->msg << " addr= " <<hex<< req->addr <<dec<< "\n");

    mcp_stalled_req[manager->getManagerID()] = 0;
    //now we should be able to occupy the evicted entry.
    hash_entry* mshr_entry = mshr->get_entry(req->addr);
    assert(mshr_entry);

    hash_entry* hash_table_entry = my_table->reserve_block_for (req->addr);
    assert(hash_table_entry);

    mshr_map[mshr_entry->get_idx()] = hash_table_entry;
    L2_algorithm (mshr_entry, req);
}