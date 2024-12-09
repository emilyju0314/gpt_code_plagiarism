int dbg_cmd_backtrace(DebugCmd cmd, const vector<string>& args)
	{
	assert(cmd == dcBacktrace);
	assert(g_frame_stack.size() > 0);

	unsigned int start_iter;
	int end_iter;

	if ( args.size() > 0 )
		{
		int how_many; // determines how we traverse the frames
		int valid_arg = sscanf(args[0].c_str(), "%i", &how_many);
		if ( ! valid_arg )
			{
			debug_msg("Argument to backtrace '%s' invalid: must be an integer\n", args[0].c_str());
			return 0;
			}

		if ( how_many > 0 )
			{ // innermost N frames
			start_iter = g_frame_stack.size() - 1;
			end_iter = start_iter - how_many + 1;
			if ( end_iter < 0 )
				end_iter = 0;
			}
		else
			{ // outermost N frames
			start_iter = how_many - 1;
			if ( start_iter + 1 > g_frame_stack.size() )
				start_iter = g_frame_stack.size() - 1;
			end_iter = 0;
			}
		}
	else
		{
		start_iter = g_frame_stack.size() - 1;
		end_iter = 0;
		}

	return dbg_backtrace_internal(start_iter, end_iter);
	}