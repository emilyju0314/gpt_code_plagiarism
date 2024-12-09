int dbg_cmd_break_set_state(DebugCmd cmd, const vector<string>& args)
	{
	assert(cmd == dcDeleteBreak || cmd == dcClearBreak || cmd == dcDisableBreak ||
	       cmd == dcEnableBreak || cmd == dcIgnoreBreak);

	if ( cmd == dcClearBreak || cmd == dcIgnoreBreak )
		{
		debug_msg("'clear' and 'ignore' commands not currently supported\n");
		return 0;
		}

	if ( g_debugger_state.breakpoints.empty() )
		{
		debug_msg("No breakpoints currently set.\n");
		return -1;
		}

	vector<int> bps_to_change;

	if ( args.empty() )
		{
		BPIDMapType::iterator iter;
		for ( iter = g_debugger_state.breakpoints.begin();
		      iter != g_debugger_state.breakpoints.end(); ++iter )
			bps_to_change.push_back(iter->second->GetID());
		}
	else
		{
		for ( const auto& arg : args )
			if ( int idx = atoi(arg.c_str()) )
				bps_to_change.push_back(idx);
		}

	for ( auto bp_change : bps_to_change )
		{
		BPIDMapType::iterator result = g_debugger_state.breakpoints.find(bp_change);

		if ( result != g_debugger_state.breakpoints.end() )
			{
			switch ( cmd )
				{
				case dcDisableBreak:
					g_debugger_state.breakpoints[bp_change]->SetEnable(false);
					debug_msg("Breakpoint %d disabled\n", bp_change);
					break;

				case dcEnableBreak:
					g_debugger_state.breakpoints[bp_change]->SetEnable(true);
					debug_msg("Breakpoint %d enabled\n", bp_change);
					break;

				case dcDeleteBreak:
					delete g_debugger_state.breakpoints[bp_change];
					g_debugger_state.breakpoints.erase(bp_change);
					debug_msg("Breakpoint %d deleted\n", bp_change);
					break;

				default:
					reporter->InternalError("Invalid command in DbgCmdBreakSetState\n");
				}
			}

		else
			debug_msg("Breakpoint %d does not exist\n", bp_change);
		}

	return -1;
	}