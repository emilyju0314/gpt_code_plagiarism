int TcpAgent::lossQuickStart()
{
       if (qs_window_ && tcp_qs_recovery_) {
                //recover_ = maxseq_;
                //reset_rtx_timer(1,0);
                slowdown(CLOSE_CWND_INIT);
		// reset ssthresh to half of W-D/2?
                qs_window_ = 0;
                output(last_ack_ + 1, TCP_REASON_DUPACK);
                return 1;
       }
       return 0;
}