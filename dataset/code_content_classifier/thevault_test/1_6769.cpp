void DCCPTCPlikeAgent::lostOrMarkedData(){
	if (cwnd_ >= 2)  //i.e . cwnd_ != 1
		cwnd_ = cwnd_ / 2;
	cwnd_frac_ = 0;
	ssthresh_ = cwnd_;
	seq_win_start_ = seq_num_;
	debug("%f, DCCP/TCPlike(%s)::lostOrMarkedData() - updated cwnd and ssthresh to: cwnd_ %d, ssthresh_ %d, seq_win_start %d\n", now(), name(), (int) cwnd_, (int) ssthresh_, seq_win_start_);
}