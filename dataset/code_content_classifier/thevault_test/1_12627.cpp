void L2_cache :: m_notify(ManagerInterface* manager)
{
    DBG_L2_CACHE(cout,  "    m_notify\n");

    Coh_msg* req = mcp_stalled_req[manager->getManagerID()];
    assert(req);

    if(manager->process_lower_client_request(req, false)) { //process the request again.
    if(my_table->get_entry(req->addr)) {
        //my_table->update_lru(req->u.coh.addr);
        }

    delete mcp_stalled_req[manager->getManagerID()];
    mcp_stalled_req[manager->getManagerID()] = 0;

    hash_entry* mshr_entry = mshr->get_entry(req->addr);

    update_hash_entry(mshr_map[mshr_entry->get_idx()], mshr_entry); //write hash_entry back.
    //mshr_map[mshr_entry->get_idx()] = 0; //cannot do this because the mapping is still used
                           //inside release_mshr_entry().
    release_mshr_entry(mshr_entry);
    }
    else {
        //do nothing since the request is already saved in mcp_stalled_req[].
    }
}