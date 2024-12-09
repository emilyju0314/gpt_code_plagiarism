void
FullTcpAgent::reset()
{
	cancel_timers();	// cancel timers first
      	TcpAgent::reset();	// resets most variables
	rq_.clear();		// clear reassembly queue
	rtt_init();		// zero rtt, srtt, backoff

	last_ack_sent_ = -1;
	rcv_nxt_ = -1;
	pipe_ = 0;
	rtxbytes_ = 0;
	flags_ = 0;
	t_seqno_ = iss_;
	maxseq_ = -1;
	irs_ = -1;
	last_send_time_ = -1.0;
	if (ts_option_)
		recent_ = recent_age_ = 0.0;
	else
		recent_ = recent_age_ = -1.0;

	fastrecov_ = FALSE;

	closed_ = 0;
	close_on_empty_ = FALSE;

        if (ecn_syn_)
                ecn_syn_next_ = 1;
        else
                ecn_syn_next_ = 0;

}