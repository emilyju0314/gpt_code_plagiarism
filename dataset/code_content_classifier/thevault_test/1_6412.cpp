void TcpAsymAgent::recv_newack_helper(Packet *pkt) 
{
	int i;
	hdr_tcp *tcph = hdr_tcp::access(pkt);
	int ackcount = tcph->seqno() - last_ack_;
	double tao = Scheduler::instance().clock() - tcph->ts_echo();

	newack(pkt);
	/* update our fine-grained estimate of the smoothed RTT */
	if (t_exact_srtt_ != 0) 
		t_exact_srtt_ = g_*tao + (1-g_)*t_exact_srtt_;
	else
		t_exact_srtt_ = tao;
/*	avg_win_ = g_*window() + (1-g_)*avg_win_;*/
	/* grow cwnd */
	for (i=0; i<ackcount; i++)
		opencwnd();
	/* if the connection is done, call finish() */
	if ((highest_ack_ >= curseq_-1) && !closed_) {
		closed_ = 1;
		finish();
	}
}