void TcpAgent::timeout_nonrtx(int tno) 
{
	if (tno == TCP_TIMER_DELSND)  {
	 /*
	 	* delayed-send timer, with random overhead
	 	* to avoid phase effects
	 	*/
		send_much(1, TCP_REASON_TIMEOUT, maxburst_);
	}
}