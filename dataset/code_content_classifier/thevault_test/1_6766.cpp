void DCCPTCPlikeAgent::updateAckRatio(int num_ack){
	debug("%f, DCCP/TCPlike(%s)::updateAckRatio() - Before: num_ack %d, in_win %d, wins %d, cwnd %d, ack_ratio %d\n", now(), name(), num_ack, num_ack_in_win_, num_win_acked_, (int) cwnd_, recv_ack_ratio_);
	if (recv_ack_ratio_ == 1){ //if ack ration is 1, we can't decrease it more
		num_ack_in_win_ = 0;
		num_win_acked_ = 0;
	} else {
		num_ack_in_win_ += num_ack;
		//only check limit when a whole window has been acked
		if (num_ack > 0 && num_ack_in_win_ >= cwnd_){
			num_win_acked_++;
			num_ack_in_win_ -= cwnd_;
			
			double ack_ratio_dec = ((double) cwnd_)/((double) (recv_ack_ratio_*(recv_ack_ratio_ - 1)));

			if (num_win_acked_ > ack_ratio_dec){
				debug("%f, DCCP/TCPlike(%s)::updateAckRatio() - Ack ratio decreased since num_win_acked_ > ack_ratio_dec\n", now(), name());
				recv_ack_ratio_--;
				checkAckRatio();
				num_win_acked_ = 0;
			}
		}
	}
	debug("%f, DCCP/TCPlike(%s)::updateAckRatio() - After: num_ack %d, in_win %d, wins %d, cwnd %d, ack_ratio %d\n", now(), name(), num_ack, num_ack_in_win_, num_win_acked_, (int) cwnd_, recv_ack_ratio_);
}