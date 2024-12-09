DCCPAgent::DCCPAgent() : Agent(PT_DCCP){
	sb_size_ = DCCP_SB_SIZE;
	opt_size_ = DCCP_OPT_SIZE; 
	feat_size_ = DCCP_FEAT_SIZE;
	ackv_size_ = DCCP_ACKV_SIZE;

	ndp_limit_ = DCCP_NDP_LIMIT;
	ccval_limit_ = DCCP_CCVAL_LIMIT;
	
	server_ = false;
	seq_num_ = 0;
	seq_num_recv_ = 0;
	ack_num_recv_ = 0;
	ackv_recv_ = NULL;
	state_ = DCCP_STATE_CLOSED;
	ack_num_ = 0;
	ccval_ = 0;
	cscov_ = DCCP_CSCOV_ALL;
	send_ack_ = 0;
	conn_est_ = false;
	output_ = false;
	output_flag_ = false;
	infinite_send_ = false;
	close_on_empty_ = false;
	ndp_ = 0;
	ccid_ = DCCP_CCID;
	use_ecn_local_ = DCCP_FEAT_DEF_ECN;
	use_ecn_remote_ = DCCP_FEAT_DEF_ECN;
	ack_ratio_local_ = DCCP_FEAT_DEF_ACK_RATIO;
	ack_ratio_remote_ = DCCP_FEAT_DEF_ACK_RATIO;
	use_ackv_local_ = DCCP_FEAT_DEF_ACKV;
	use_ackv_remote_ = DCCP_FEAT_DEF_ACKV;
	q_scheme_ = DCCP_FEAT_DEF_Q_SCHEME;
	q_local_ = DCCP_FEAT_DEF_Q;
	q_remote_ = DCCP_FEAT_DEF_Q;
	
	feat_list_num_ = new u_int8_t[feat_size_];
	feat_list_loc_ = new dccp_feature_location[feat_size_];
	feat_list_seq_num_ = new u_int32_t[feat_size_];
	feat_list_first_ = new bool[feat_size_];
	feat_list_used_ = 0;

	feat_conf_num_ = new u_int8_t[feat_size_];
	feat_conf_loc_ = new dccp_feature_location[feat_size_];
	feat_conf_used_ = 0;

	seq_last_feat_neg_ = 0;
	feat_first_in_pkt_ = true;

	allow_mult_neg_ = 0;
	
	packet_sent_ = false;
	packet_recv_ = false;
	
	sb_ = new DCCPSendBuffer(sb_size_);
	opt_ = new DCCPOptions(opt_size_);
	ackv_ = new DCCPAckVector(ackv_size_);
	
	send_ackv_ = true;
	manage_ackv_ = true;

	elapsed_time_recv_ = 0;
	nonces_ = new RNG();
	nonces_->set_seed((long int) 0);

	timer_rtx_ = new DCCPRetransmitTimer(this);
	timer_snd_ = new DCCPSendTimer(this);
	
	snd_delay_ = DCCP_SND_DELAY;

	nam_tracevar_ = false;
	trace_all_oneline_ = false;

	ar_unacked_ = 0;

	rtt_conn_est_ = 0.0;
	
	initial_rtx_to_ = DCCP_INITIAL_RTX_TO;
	max_rtx_to_ = DCCP_MAX_RTX_TO;
	resp_to_ = DCCP_RESP_TO;

	num_data_pkt_ = 0;
	num_ack_pkt_ = 0;
	num_dataack_pkt_ = 0;
}