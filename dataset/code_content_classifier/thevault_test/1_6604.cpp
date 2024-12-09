void TcpAgent::quench(int how)
{
	if (highest_ack_ >= recover_) {
		recover_ =  maxseq_;
		last_cwnd_action_ = CWND_ACTION_ECN;
		closecwnd(how);
	}
}