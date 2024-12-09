void
TcpAgent::send_one()
{
	if (t_seqno_ <= highest_ack_ + wnd_ && t_seqno_ < curseq_ &&
		t_seqno_ <= highest_ack_ + cwnd_ + dupacks_ ) {
		output(t_seqno_, 0);
		if (QOption_)
			process_qoption_after_send () ;
		t_seqno_ ++ ;
		// send_helper(); ??
	}
	return;
}