void Controller :: handle_request(int, Coh_mem_req* req)
{
    if(req->u.mem.op_type == OpMemLd) {
#ifdef DBG_CAFFDRAM
cout << "mc received LD, src= " << req->u.mem.source_id << " port= " <<req->u.mem.source_port << " addr= " <<hex<< req->u.mem.addr <<dec<<endl;
#endif
    //stats
    m_ld_misses[req->u.mem.source_id]++;
    /*
    m_req_info.insert(pair<Ticks_t, Req_info>(Manifold::NowTicks(),
                                              Req_info(OpMemLd, req->u.mem.originator_id, req->u.mem.source_id, req->u.mem.addr)));
                          */

    req->u.mem.msg = LD_RESPONSE;
    //req->u.mem.req_id = req->u.mem.req_id;
    req->u.mem.dest_id = req->u.mem.source_id;
    req->u.mem.dest_port = req->u.mem.source_port;
    req->u.mem.source_id = m_nid;
    req->u.mem.source_port = 0;
    Ticks_t latency = processRequest(req->u.mem.addr, Manifold::NowTicks()); //????????????? using default clock here.
    //The return value of processRequest() is the actual (or absolute) time of when the request
    //is completed, but Sendtick requires time relative to now. So we must pass to SendTick
    //the return value - now.
    SendTick(PORT0, req, latency - Manifold::NowTicks());
    }
    else {
#ifdef DBG_CAFFDRAM
cout << "mc received ST, src= " << req->u.mem.source_id << " port= " <<req->u.mem.source_port << " addr= " <<hex<< req->u.mem.addr <<dec<<endl;
#endif
    //stats
    m_stores[req->u.mem.source_id]++;
    /*
    m_req_info.insert(pair<Ticks_t, Req_info>(Manifold::NowTicks(),
                                              Req_info(OpMemSt, req->u.mem.originator_id, req->u.mem.source_id, req->u.mem.addr)));
                          */
    Ticks_t latency = processRequest(req->u.mem.addr, Manifold::NowTicks()); //????????????? using default clock here.
        if(m_send_st_response) {
        req->u.mem.msg = ST_COMPLETE;
        //req->u.mem.req_id = req->u.mem.req_id;
        req->u.mem.dest_id = req->u.mem.source_id;
        req->u.mem.dest_port = req->u.mem.source_port;
        req->u.mem.source_id = m_nid;
        req->u.mem.source_port = 0;
        //The return value of processRequest() is the actual (or absolute) time of when the request
        //is completed, but Sendtick requires time relative to now. So we must pass to SendTick
        //the return value - now.
        SendTick(PORT0, req, latency - Manifold::NowTicks());
    }
    }

}