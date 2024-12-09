int BayFullTcpAgent::need_send()
{
	//first cut, send if anything to ack. Might need maxseg_
	if(flags_ & TF_ACKNOW)
		return 1;
	if(rcv_nxt_ < switch_spa_thresh_)
		return ((rcv_nxt_ - last_ack_sent_) >= 1);
	return ((rcv_nxt_ - last_ack_sent_) >= (segs_per_ack_ * maxseg_));
}