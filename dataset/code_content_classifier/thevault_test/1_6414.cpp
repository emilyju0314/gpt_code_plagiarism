void
TcpAsymAgent::traceAll() {
	double curtime;
	Scheduler& s = Scheduler::instance();
	char wrk[500];
	int n;

	TcpAgent::traceAll();
	curtime = &s ? s.clock() : 0;
	sprintf(wrk, "time: %-8.5f saddr: %-2d sport: %-2d daddr: %-2d dport:"
		" %-2d exact_srtt %d", curtime, addr(), port(),
		daddr(), dport(), (int(t_exact_srtt_)));
	n = strlen(wrk);
	wrk[n] = '\n';
	wrk[n+1] = 0;
	if (channel_)
		(void)Tcl_Write(channel_, wrk, n+1);
	wrk[n] = 0;
	return;
}