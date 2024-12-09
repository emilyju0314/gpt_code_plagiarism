void TcpAgent::spurious_timeout()
{
	frto_ = 0;

	switch (spurious_response_) {
	case 1:
	default:
		/*
		 * Full revert of congestion window
		 * (FlightSize before last acknowledgment)
		 */
		cwnd_ = t_seqno_ - prev_highest_ack_;
		break;
 
	case 2:
		/*
		 * cwnd = reduced ssthresh (approx. half of the earlier pipe)
		 */
		cwnd_ = ssthresh_; break;
	case 3:
		/*
		 * slow start, but without retransmissions
		 */
		cwnd_ = 1; break;
	}

	/*
	 * Revert ssthresh to size before retransmission timeout
	 */
	ssthresh_ = pipe_prev_;

	/* If timeout was spurious, bugfix is not needed */
	recover_ = highest_ack_ - 1;
}