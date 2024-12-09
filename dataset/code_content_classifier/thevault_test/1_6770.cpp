bool DCCPTCPlikeAgent::detectQuiescence(){
	debug("%f, DCCP/TCPlike(%s)::detectQuiescence() - scheme %d, seq high data %d, last in vect %d, time now %f, time high data %f, srtt %f\n", now(), name(), q_scheme_, q_high_data_recv_, ackv_->getLastSeqNum(),now(),q_t_data_,(double) srtt_);

	if (q_scheme_ == DCCP_Q_SCHEME_Q_OPT){
		if(sender_quiescent_)
			debug("%f, DCCP/TCPlike(%s)::detectQuiescence() - Receiver detected that the corresponding sender is quiescent (Q_OPT)\n", now(),name());
		return sender_quiescent_;
	} else if (q_scheme_ == DCCP_Q_SCHEME_Q_FEAT){
		if (q_local_)
			debug("%f, DCCP/TCPlike(%s)::detectQuiescence() - Receiver detected that the corresponding sender is quiescent (Q_FEAT)\n", now(),name());
		return q_local_;
	}
	
	if (srtt_ <= 0.0)
		return false;
	
	double t = q_min_t_;
	if (t < 2*srtt_)  
		t = 2*srtt_; 
	if (ackv_->getLastSeqNum() > q_high_data_recv_ && now()-q_t_data_ >= t)
		debug("%f, DCCP/TCPlike(%s)::detectQuiescence() - Receiver detected that the corresponding sender is quiescent (NORMAL)\n", now(), name());
	return (ackv_->getLastSeqNum() > q_high_data_recv_ && now()-q_t_data_ >= t);
}