DCCPAckVector::DCCPAckVector(u_int16_t initialSize){
	vector_ = new u_char[initialSize];
	size_ = 0;
	max_size_ = initialSize;
	ene_ = 0;
	head_ = 0;
	tail_ = 0;
	seq_head_ = 0;
	seq_tail_ = 0;
	p_walk_ = 0;
	seq_p_walk_ = 0;
	delta_p_walk_ = 0;
	p_walking_ = false;
	p_reverse_ = false;
	i_walk_ = 0;
	seq_i_walk_ = 0;
	i_walking_ = false;

	ackv_cons_[DCCP_PACKET_RECV][DCCP_PACKET_RECV]         = DCCP_PACKET_RECV;
	ackv_cons_[DCCP_PACKET_RECV][DCCP_PACKET_ECN]          = DCCP_PACKET_RECV;
	ackv_cons_[DCCP_PACKET_RECV][DCCP_PACKET_RESERVED]     = DCCP_PACKET_RESERVED;
	ackv_cons_[DCCP_PACKET_RECV][DCCP_PACKET_NOT_RECV]     = DCCP_PACKET_RECV;
	ackv_cons_[DCCP_PACKET_ECN][DCCP_PACKET_RECV]          = DCCP_PACKET_ECN;
	ackv_cons_[DCCP_PACKET_ECN][DCCP_PACKET_ECN]           = DCCP_PACKET_ECN;
	ackv_cons_[DCCP_PACKET_ECN][DCCP_PACKET_RESERVED]      = DCCP_PACKET_RESERVED;
	ackv_cons_[DCCP_PACKET_ECN][DCCP_PACKET_NOT_RECV]      = DCCP_PACKET_ECN;
	ackv_cons_[DCCP_PACKET_RESERVED][DCCP_PACKET_RECV]     = DCCP_PACKET_RESERVED;
	ackv_cons_[DCCP_PACKET_RESERVED][DCCP_PACKET_ECN]      = DCCP_PACKET_RESERVED;
	ackv_cons_[DCCP_PACKET_RESERVED][DCCP_PACKET_RESERVED] = DCCP_PACKET_RESERVED;
	ackv_cons_[DCCP_PACKET_RESERVED][DCCP_PACKET_NOT_RECV] = DCCP_PACKET_RESERVED;
	ackv_cons_[DCCP_PACKET_NOT_RECV][DCCP_PACKET_RECV]     = DCCP_PACKET_RECV;
	ackv_cons_[DCCP_PACKET_NOT_RECV][DCCP_PACKET_ECN]      = DCCP_PACKET_ECN;
	ackv_cons_[DCCP_PACKET_NOT_RECV][DCCP_PACKET_RESERVED] = DCCP_PACKET_RESERVED;
	ackv_cons_[DCCP_PACKET_NOT_RECV][DCCP_PACKET_NOT_RECV] = DCCP_PACKET_NOT_RECV;
	
	STAILQ_INIT(&ack_hist_);
}