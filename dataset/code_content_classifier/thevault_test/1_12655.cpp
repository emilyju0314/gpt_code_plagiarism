bool CmbSyncAlg :: send_null_msgs(Clock* clk)
{
#ifdef GET_NULL_MSG_TIME
    struct timeval t_start;
    gettimeofday(&t_start, NULL);
#endif
    bool useful_update = false;

    static std::vector<LpId_t>* succs=&(Manifold::get_scheduler()->get_successors());
    static int SuccsSize = succs->size();

    int src=Manifold::GetRank();

    // This function is called when the timestamp of the earliest event < min-null,
    // where min-null is the min timestamp of all the input NULL messages.
    //
    // FOREACH successor succ {
    //     send NULL = min-null + lookahead to succ
    //

    for(size_t i=0; i<SuccsSize; i++) {
	Time_t clockTime;
	if(clk->nextRising)
	    clockTime = clk->nextTick/clk->freq;
	else
	    clockTime = (clk->nextTick+1)/clk->freq;

	Time_t newEot = (m_min_null > clockTime) ? m_min_null : clockTime + m_lookahead->GetLookahead(src, (*succs)[i]);
	Time_t oldEot=m_eots[i];

	assert(newEot>=oldEot);

	if(newEot > oldEot) { // only send if necessary
//cout.precision(10);
//cout << "MMMMM " << " send null " << newEot << " to " << (*succs)[i] << " @ " << Manifold::NowTicks() << " rising= " << Clock::Master().nextRising << "  min_null= " << m_min_null << endl;
	    NullMsg_t* msg = new NullMsg_t();
	    msg->src = src;
	    msg->dst = (*succs)[i];
	    m_eots[i]=newEot;
	    msg->t=newEot;
	    TheMessenger.SendNullMsg(msg);
	    delete msg;
	    #ifdef STATS
	    stats_sent_null[(*succs)[i]]++;
	    #endif
	    useful_update = true;
	}
    }
#ifdef GET_NULL_MSG_TIME
    struct timeval t_end;
    gettimeofday(&t_end, NULL);
    double t_diff = (t_end.tv_sec - t_start.tv_sec)*1000000 + (t_end.tv_usec - t_start.tv_usec);

    if(useful_update) {
        null_msg_send_time += t_diff;
    }
    else
        null_msg_wasted_send_time += t_diff;
#endif

return useful_update;
}