void
TcpAgent::traceVar(TracedVar* v) 
{
	if (!channel_)
		return;

	double curtime;
	Scheduler& s = Scheduler::instance();
	char wrk[TCP_WRK_SIZE];

	curtime = &s ? s.clock() : 0;

	// XXX comparing addresses is faster than comparing names
	if (v == &cwnd_)
		snprintf(wrk, TCP_WRK_SIZE,
			 "%-8.5f %-2d %-2d %-2d %-2d %s %-6.3f\n",
			 curtime, addr(), port(), daddr(), dport(),
			 v->name(), double(*((TracedDouble*) v))); 
 	else if (v == &t_rtt_)
		snprintf(wrk, TCP_WRK_SIZE,
			 "%-8.5f %-2d %-2d %-2d %-2d %s %-6.3f\n",
			 curtime, addr(), port(), daddr(), dport(),
			 v->name(), int(*((TracedInt*) v))*tcp_tick_); 
	else if (v == &t_srtt_)
		snprintf(wrk, TCP_WRK_SIZE,
			 "%-8.5f %-2d %-2d %-2d %-2d %s %-6.3f\n",
			 curtime, addr(), port(), daddr(), dport(),
			 v->name(), 
			 (int(*((TracedInt*) v)) >> T_SRTT_BITS)*tcp_tick_); 
	else if (v == &t_rttvar_)
		snprintf(wrk, TCP_WRK_SIZE,
			 "%-8.5f %-2d %-2d %-2d %-2d %s %-6.3f\n",
			 curtime, addr(), port(), daddr(), dport(),
			 v->name(), 
			 int(*((TracedInt*) v))*tcp_tick_/4.0); 
	else
		snprintf(wrk, TCP_WRK_SIZE,
			 "%-8.5f %-2d %-2d %-2d %-2d %s %d\n",
			 curtime, addr(), port(), daddr(), dport(),
			 v->name(), int(*((TracedInt*) v))); 

	(void)Tcl_Write(channel_, wrk, -1);
}