int dbg_cmd_break_condition(DebugCmd cmd, const vector<string>& args)
	{
	assert(cmd == dcBreakCondition);

	if ( args.size() < 2 )
		{
		debug_msg("Arguments must specify breakpoint number and condition.\n");
		return 0;
		}

	int idx = atoi(args[0].c_str());
	DbgBreakpoint* bp = g_debugger_state.breakpoints[idx];

	string expr;
	for ( int i = 1; i < int(args.size()); ++i )
		{
		expr += args[i];
		expr += " ";
		}
	bp->SetCondition(expr);

	return 1;
	}