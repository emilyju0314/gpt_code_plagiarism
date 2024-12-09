void CmbSyncAlg :: send_null_msgs_with_forecast(Clock* clk)
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

    Time_t min_newEot;

    Time_t clockTime;
    if(clk->nextRising)
        clockTime = clk->nextTick/clk->freq;
    else
        clockTime = (clk->nextTick+1)/clk->freq;

    std::map<LpId_t, Ticks_t> forecast_map;

    for(size_t i=0; i<SuccsSize; i++) {
	LpId_t succ = (*succs)[i];
	Time_t newEot = (m_min_null > clockTime) ? m_min_null : clockTime + m_lookahead->GetLookahead(src, succ);

	Ticks_t forecast = 0;

	if(m_outputTS->m_ticks[src][succ] > 0)
	    forecast = m_outputTS->m_ticks[src][succ];

	if(m_outputTS->m_ticks[src][succ] > 0 && m_in_forecast_ticks[succ] > 0) {
	    Time_t null_ts = 0; //timestamp for null msg

	    if(m_outputTS->m_ticks[src][succ] > m_in_forecast_ticks[succ]) {
		const Ticks_t LINK_DELAY = 1; //assuming link delay is 1 tick

		Ticks_t tick = m_in_forecast_ticks[succ] + LINK_DELAY; //m_in_forecast_ticks is predicted send time; send_time + delay = recv_time.
		null_ts = tick/clk->freq + m_lookahead->GetLookahead(src, succ);
//cout << "succ= " << succ << " my forecast= " << m_outputTS->m_ticks[src][succ] << " other forecast= " << m_in_forecast_ticks[succ] << " use other\n";
	    }
	    else {
		null_ts = m_outputTS->m_times[src][succ] + m_lookahead->GetLookahead(src, succ);
//cout << "succ= " << succ << " my forecast= " << m_outputTS->m_ticks[src][succ] << " other forecast= " << m_in_forecast_ticks[succ] << " use mine\n";
	    }

	    if(null_ts > newEot)
		newEot = null_ts;
	    m_outputTS->m_times[src][succ] = 0;
	    m_outputTS->m_prev_ticks[src][succ] = m_outputTS->m_ticks[src][succ];
	    m_outputTS->m_ticks[src][succ] = 0;
	}

	if(i==0)
	    min_newEot = newEot;
	else if(newEot < min_newEot)
	    min_newEot = newEot;

	forecast_map[succ] = forecast;
    }//for each successor


    for(size_t i=0; i<SuccsSize; i++) {
	Time_t clockTime;
	if(clk->nextRising)
	    clockTime = clk->nextTick/clk->freq;
	else
	    clockTime = (clk->nextTick+1)/clk->freq;

	LpId_t succ = (*succs)[i];

	Time_t oldEot=m_eots[i];

	if(min_newEot > oldEot) { // only send if necessary
            NullMsg_t* msg = new NullMsg_t();
            msg->src = src;
            msg->dst = succ;
            m_eots[i]=min_newEot;
            msg->t=min_newEot;
            msg->forecast = forecast_map[succ];
            TheMessenger.SendNullMsg(msg);
            delete msg;
	    #ifdef STATS
	    stats_sent_null[succ]++;
	    #endif
	    useful_update = true;
#if 0
cout.precision(10);
cout << "NULLNULL " << " send null " << min_newEot << " to " << succ << " @ " << Manifold::NowTicks() << " rising= " << Clock::Master().nextRising << "  min_null= " << m_min_null << " forecast= " << forecast_map[succ] << "  in fcast= " << m_in_forecast_ticks[succ] << endl;
cout.flush();
#endif
	}
    }//for
#ifdef GET_NULL_MSG_TIME
    struct timeval t_end;
    gettimeofday(&t_end, NULL);
    double t_diff = (t_end.tv_sec - t_start.tv_sec)*1000000 + (t_end.tv_usec - t_start.tv_usec);

    if(useful_update)
        null_msg_send_time += t_diff;
    else
        null_msg_wasted_send_time += t_diff;
#endif
}