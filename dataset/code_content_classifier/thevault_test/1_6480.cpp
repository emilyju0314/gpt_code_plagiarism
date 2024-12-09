int
FullTcpAgent::need_send()
{
	if (flags_ & TF_ACKNOW)
		return TRUE;

	int spa = (spa_thresh_ > 0 && ((rcv_nxt_ - irs_)  < spa_thresh_)) ?
		1 : segs_per_ack_;
		
	return ((rcv_nxt_ - last_ack_sent_) >= (spa * maxseg_));
}