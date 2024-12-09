DCCPTCPlikeAgent::DCCPTCPlikeAgent() : DCCPAgent() {
	ccid_ = DCCP_TCPLIKE_CCID;

	initial_cwnd_ = DCCP_TCPLIKE_INIT_CWND;
	initial_ssthresh_ = DCCP_TCPLIKE_INIT_SSTHRESH;
	initial_rto_ = DCCP_TCPLIKE_INIT_RTO;
	cwnd_timeout_ = DCCP_TCPLIKE_CWND_TO;

	cwnd_ = initial_cwnd_;
	cwnd_frac_ = 0;
	ssthresh_ = initial_ssthresh_;
	pipe_ = 0;

	t_last_data_sent_ = (double) (-DCCP_TCPLIKE_MIN_T)*2;
	q_opt_ratio_ = DCCP_TCPLIKE_QUIESCENCE_OPT_RATIO;
	q_packets_wo_opt_ = 0;
	
	rto_ = initial_rto_;
	srtt_ = -1.0;
	rttvar_ = 0.0;
	rtt_sample_ = 0.0;
	k_ = DCCP_TCPLIKE_K;
	g_ = DCCP_TCPLIKE_G;
	alpha_ = DCCP_TCPLIKE_ALPHA;
	beta_ = DCCP_TCPLIKE_BETA;

	min_rto_ = DCCP_TCPLIKE_MIN_RTO;
	
	num_dup_acks_ = DCCP_NUM_DUP_ACKS;

	STAILQ_INIT(&send_hist_);
	STAILQ_INIT(&send_recv_hist_);
	
	timer_to_ = new DCCPTCPlikeTOTimer(this);
	timer_dack_ = new DCCPTCPlikeDelayedAckTimer(this);
	
	hist_last_seq_ = 0;
	high_ack_recv_ = 0;
	
	high_seq_recv_ = 0;
	high_ndp_recv_ = -1;
	unacked_ = 0;

	stored_ackv_ = new DCCPAckVector(ackv_size_);
	stored_ackv_->ackv_cons_[DCCP_PACKET_RECV][DCCP_PACKET_RECV]         = DCCP_PACKET_RECV;
	stored_ackv_->ackv_cons_[DCCP_PACKET_RECV][DCCP_PACKET_ECN]          = DCCP_PACKET_ECN;
	stored_ackv_->ackv_cons_[DCCP_PACKET_RECV][DCCP_PACKET_RESERVED]     = DCCP_PACKET_RESERVED;
	stored_ackv_->ackv_cons_[DCCP_PACKET_RECV][DCCP_PACKET_NOT_RECV]     = DCCP_PACKET_RECV;
	stored_ackv_->ackv_cons_[DCCP_PACKET_ECN][DCCP_PACKET_RECV]          = DCCP_PACKET_ECN;
	stored_ackv_->ackv_cons_[DCCP_PACKET_ECN][DCCP_PACKET_ECN]           = DCCP_PACKET_ECN;
	stored_ackv_->ackv_cons_[DCCP_PACKET_ECN][DCCP_PACKET_RESERVED]      = DCCP_PACKET_RESERVED;
	stored_ackv_->ackv_cons_[DCCP_PACKET_ECN][DCCP_PACKET_NOT_RECV]      = DCCP_PACKET_ECN;
	stored_ackv_->ackv_cons_[DCCP_PACKET_RESERVED][DCCP_PACKET_RECV]     = DCCP_PACKET_RESERVED;
	stored_ackv_->ackv_cons_[DCCP_PACKET_RESERVED][DCCP_PACKET_ECN]      = DCCP_PACKET_RESERVED;
	stored_ackv_->ackv_cons_[DCCP_PACKET_RESERVED][DCCP_PACKET_RESERVED] = DCCP_PACKET_RESERVED;
	stored_ackv_->ackv_cons_[DCCP_PACKET_RESERVED][DCCP_PACKET_NOT_RECV] = DCCP_PACKET_RESERVED;
	stored_ackv_->ackv_cons_[DCCP_PACKET_NOT_RECV][DCCP_PACKET_RECV]     = DCCP_PACKET_RECV;
	stored_ackv_->ackv_cons_[DCCP_PACKET_NOT_RECV][DCCP_PACKET_ECN]      = DCCP_PACKET_ECN;
	stored_ackv_->ackv_cons_[DCCP_PACKET_NOT_RECV][DCCP_PACKET_RESERVED] = DCCP_PACKET_RESERVED;
	stored_ackv_->ackv_cons_[DCCP_PACKET_NOT_RECV][DCCP_PACKET_NOT_RECV] = DCCP_PACKET_NOT_RECV;
	seq_all_done_ = 0;
	seq_win_start_ = 0;
	seq_pipe_start_ = 0;
	
	num_win_acked_ = 0;
	num_ack_in_win_ = 0;
	ack_win_start_ = 0;
	skip_ack_loss_ = false;
	recv_ack_ratio_ = ack_ratio_remote_;

	q_high_data_recv_ = 0;
	q_t_data_ = 0.0;
	q_min_t_ = DCCP_TCPLIKE_MIN_T;

	ackv_size_lim_ = DCCP_TCPLIKE_ACKV_SIZE_LIM; 
	ackv_lim_seq_ = 0; 

	sender_quiescent_ = false;
	
	dack_delay_ = DCCP_TCPLIKE_DACK_DELAY;
	t_high_recv_ = 0.0;

	//test conversion from bool to int
	if (!((int) (cwnd_ >= cwnd_frac_) == 0 || (int) (cwnd_ >= cwnd_frac_) == 1)){
		fprintf(stderr,"DCCP/TCPlike::DCCPTCPlikeAgent() - The conversion between bool and int is not as expected ((int) (%d >= %d) = %d)!\n", (int) cwnd_, (int) cwnd_frac_, (int) (cwnd_ >= cwnd_frac_));
		fflush(stdout);
		abort();
	} else if (!((int) (cwnd_ < cwnd_frac_) == 0 || (int) (cwnd_ < cwnd_frac_) == 1)){
		fprintf(stderr,"DCCP/TCPlike::DCCPTCPlikeAgent() - The conversion between bool and int is not as expected ((int) (%d < %d) = %d)!\n", (int) cwnd_, (int) cwnd_frac_, (int) (cwnd_ < cwnd_frac_));
		fflush(stdout);
		abort();
	}
		
}