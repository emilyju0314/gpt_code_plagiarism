void DCCPTCPlikeAgent::updateCwnd(int num_inc_cwnd){
	debug("%f, DCCP/TCPlike(%s)::updateCwnd() - Before: num_inc_cwnd %d,  cwnd_ %d, cwnd_frac_ %d, ssthresh_ %d, ack_ratio_remote_ %d\n", now(),name(), num_inc_cwnd, (int) cwnd_, (int) cwnd_frac_,(int) ssthresh_, ack_ratio_remote_);
	int old_cwnd = cwnd_;

	if (cwnd_ < ssthresh_){ //slow start
		if (num_inc_cwnd > ack_ratio_remote_){
			cwnd_ += ack_ratio_remote_;
			num_inc_cwnd -= ack_ratio_remote_;
		} else {
			cwnd_ += num_inc_cwnd;
			num_inc_cwnd = 0;
		}
		
		if (cwnd_ <  ssthresh_)
			num_inc_cwnd = 0;
		else {
			num_inc_cwnd += (cwnd_ - ssthresh_);
			cwnd_ = ssthresh_;
		}
		if (cwnd_ == ssthresh_){ //we passed ssthresh_
			cwnd_frac_ = 0;
			//check quiescence and send ack of ack if needed
			if (detectQuiescence()){ 
				//output_ = true;
				send_ack_ = true;
				ack_num_ = seq_num_recv_;
			}
		}
	}
	
	if (num_inc_cwnd > 0 && cwnd_ >= ssthresh_){ //congestion avoidance
		cwnd_frac_ += num_inc_cwnd;
		while (cwnd_frac_ >= cwnd_){
			cwnd_frac_ -= cwnd_;
			cwnd_++;
		}

		//check quiescence and send ack of ack if needed
		if (cwnd_ != old_cwnd && detectQuiescence()){
			//output_ = true;
			send_ack_ = true;
			ack_num_ = seq_num_recv_;
		} 
	}

	if (old_cwnd < cwnd_)
		if (checkAckRatio())
			debug("%f, DCCP/TCPlike(%s)::updateCwnd() - Ack ratio changed! old_cwnd %d cwnd_ %d\n", now(), name(), old_cwnd, (int) cwnd_);
	
	debug("%f, DCCP/TCPlike(%s)::updateCwnd() - After: num_inc_cwnd %d, cwnd_ %d, cwnd_frac_ %d, ssthresh_ %d, ack_ratio_remote_ %d\n", now(), name(), num_inc_cwnd, (int) cwnd_, (int) cwnd_frac_, (int) ssthresh_, ack_ratio_remote_);
}