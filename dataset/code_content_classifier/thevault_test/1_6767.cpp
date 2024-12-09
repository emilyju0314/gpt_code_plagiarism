void DCCPTCPlikeAgent::lostOrMarkedAck(){
	ack_win_start_ = seq_num_;
	num_win_acked_ = 0;
	num_ack_in_win_ = 0;
	skip_ack_loss_ = true;
	recv_ack_ratio_ *= 2;
	checkAckRatio();
}