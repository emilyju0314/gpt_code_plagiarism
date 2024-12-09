void
FullTcpAgent::reset_rtx_timer(int /* mild */)
{
	// cancel old timer, set a new one
	/* if there is no outstanding data, don't back off rtx timer *
	 * (Fix from T. Kelly.) */
	if (!(highest_ack_ == maxseq_ && restart_bugfix_)) {
        	rtt_backoff();		// double current timeout
	}
        set_rtx_timer();	// set new timer
        rtt_active_ = FALSE;	// no timing during this window
}