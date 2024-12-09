int dbg_cmd_frame(DebugCmd cmd, const vector<string>& args)
	{
	assert(cmd == dcFrame || cmd == dcUp || cmd == dcDown);

	if ( cmd == dcFrame )
		{
		int idx = 0;

		if ( args.size() > 0 )
			{
			if ( args.size() > 1 )
				{
				debug_msg("Too many arguments: expecting frame number 'n'\n");
				return 0;
				}

			if ( ! sscanf(args[0].c_str(), "%d", &idx) )
				{
				debug_msg("Argument to frame must be a positive integer\n");
				return 0;
				}

			if ( idx < 0 || (unsigned int)idx >= g_frame_stack.size() )
				{
				debug_msg("No frame %d", idx);
				return 0;
				}
			}

		g_debugger_state.curr_frame_idx = idx;
		}

	else if ( cmd == dcDown )
		{
		if ( g_debugger_state.curr_frame_idx == 0 )
			{
			debug_msg("Innermost frame already selected\n");
			return 0;
			}

		g_debugger_state.curr_frame_idx--;
		}

	else if ( cmd == dcUp )
		{
		if ( (unsigned int)(g_debugger_state.curr_frame_idx + 1) == g_frame_stack.size() )
			{
			debug_msg("Outermost frame already selected\n");
			return 0;
			}

		++g_debugger_state.curr_frame_idx;
		}

	int user_frame_number = g_frame_stack.size() - 1 - g_debugger_state.curr_frame_idx;

	// Set the current location to the new frame being looked at
	// for 'list', 'break', etc.
	const Stmt* stmt = g_frame_stack[user_frame_number]->GetNextStmt();
	if ( ! stmt )
		reporter->InternalError("Assertion failed: %s", "stmt != 0");

	const Location loc = *stmt->GetLocationInfo();
	g_debugger_state.last_loc = loc;
	g_debugger_state.already_did_list = false;

	return dbg_backtrace_internal(user_frame_number, user_frame_number);
	}