void L2_cache::L2_algorithm (hash_entry* mshr_entry, Coh_msg* request)
{
    DBG_L2_CACHE(cout, "    L2_cache :: L2_algorithm(), addr= " << hex << request->addr << dec << endl);

    ManagerInterface* manager = managers[mshr_map[mshr_entry->get_idx()]->get_idx()];
    assert(mcp_stalled_req[manager->getManagerID()] == 0);


    if(mshr_entry->get_have_data())
    {
        if(manager->process_lower_client_request(request, true)) {
        if(my_table->get_entry(request->addr)) {
        //my_table->update_lru(request->u.coh.addr);
        }
        delete request;
        update_hash_entry(mshr_map[mshr_entry->get_idx()], mshr_entry); //write hash_entry back.
        release_mshr_entry(mshr_entry);
    }
    else {
        mcp_stalled_req[manager->getManagerID()] = request;
    }
    }
    else
    {
        stats_miss++;
        get_from_memory(request);
        mcp_stalled_req[manager->getManagerID()] = request; //necessary for wakeup when response comes back.
    }
}