void TcpAgent::endQuickStart()
{
	qs_approved_ = 0;
        qs_cwnd_ = 0;
        qs_window_ = maxseq_;
	int new_cwnd = maxseq_ - last_ack_;
	if (new_cwnd > 1 && new_cwnd < cwnd_) {
	 	cwnd_ = new_cwnd;
		if (cwnd_ < initial_window()) 
			cwnd_ = initial_window();
	}
}