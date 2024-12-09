void TcpAsymAgent::traceVar(TracedVar* v) {
	Scheduler& s = Scheduler::instance();
	char wrk[500];

	double curtime = &s ? s.clock() : 0;
	if (!strcmp(v->name(), "exact_srtt_"))
		sprintf(wrk,"%-8.5f %-2d %-2d %-2d %-2d %s %-6.3f", 
			curtime, addr(), port(), daddr(), dport(),
			v->name(), double(*((TracedDouble*) v)));
	else if (!strcmp(v->name(), "avg_win_"))
		sprintf(wrk,"%-8.5f %-2d %-2d %-2d %-2d %s %-6.3f", 
			curtime, addr(), port(), daddr(), dport(), 
			v->name(), double(*((TracedDouble*) v)));
	else {
		TcpAgent::traceVar(v);
		return;
	}

	int n = strlen(wrk);
	wrk[n] = '\n';
	wrk[n+1] = 0;
	if (channel_)
		(void)Tcl_Write(channel_, wrk, n+1);
	wrk[n] = 0;
	return;
}