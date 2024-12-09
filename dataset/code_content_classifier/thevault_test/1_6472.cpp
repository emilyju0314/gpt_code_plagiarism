void
FullTcpAgent::pack_action(Packet*)
{
	if (reno_fastrecov_ && fastrecov_ && cwnd_ > double(ssthresh_)) {
		cwnd_ = double(ssthresh_); // retract window if inflated
	}
	fastrecov_ = FALSE;
//printf("%f: EXITED FAST RECOVERY\n", now());
	dupacks_ = 0;
}