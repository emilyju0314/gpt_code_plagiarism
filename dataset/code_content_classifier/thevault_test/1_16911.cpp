static int dbg_backtrace_internal(int start, int end)
	{
	if ( start < 0 || end < 0 || (unsigned)start >= g_frame_stack.size() ||
	     (unsigned)end >= g_frame_stack.size() )
		reporter->InternalError("Invalid stack frame index in DbgBacktraceInternal\n");

	if ( start < end )
		{
		int temp = start;
		start = end;
		end = temp;
		}

	for ( int i = start; i >= end; --i )
		{
		const Frame* f = g_frame_stack[i];
		const Stmt* stmt = f ? f->GetNextStmt() : nullptr;

		string context = get_context_description(stmt, f);
		debug_msg("#%d  %s\n", int(g_frame_stack.size() - 1 - i), context.c_str());
		};

	return 1;
	}