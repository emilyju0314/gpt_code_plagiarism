bool DCCPTCPlikeAgent::checkAckRatio(){
	bool result = false;
	int temp = cwnd_ / 2;
	if (cwnd_ % 2 > 0)
		temp++;

	//ackratio is never greater than half cwnd (rounded up)
	if(recv_ack_ratio_ > temp){  
		recv_ack_ratio_ = temp;
		result = true;
	}
	//ack ratio always >= 2 for cwnd >= 4
	if (cwnd_ >= 4 && recv_ack_ratio_ < 2){
		recv_ack_ratio_ = 2;
		result = true;
	} else if (recv_ack_ratio_ == 0){  //always an integer > 0
		recv_ack_ratio_ = 1;
		result = true;
	}

	return result;
}