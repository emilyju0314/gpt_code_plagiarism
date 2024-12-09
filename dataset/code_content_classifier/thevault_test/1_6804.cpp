void
BayFullTcpAgent::reset()
{
	TcpAgent::reset();
	highest_ack_ = 0;
	last_ack_sent_ = 0;
	rcv_nxt_ = 0;		//kmn
	flags_ = 0;
	t_seqno_ = iss_;
	close_on_empty_ = 0;	//added 7/30/97 by kmn
	switch_spa_thresh_ = 0;
	first_data_ = 0;		//don't open cwnd too early
}