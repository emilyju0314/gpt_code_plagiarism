int dbg_cmd_print(DebugCmd cmd, const vector<string>& args)
	{
	assert(cmd == dcPrint);

	// ### TODO: add support for formats

	// Just concatenate all the 'args' into one expression.
	string expr;
	for ( size_t i = 0; i < args.size(); ++i )
		{
		expr += args[i];
		if ( i < args.size() - 1 )
			expr += " ";
		}

	auto val = dbg_eval_expr(expr.c_str());

	if ( val )
		{
		ODesc d;
		val->Describe(&d);
		debug_msg("%s\n", d.Description());
		}
	else
		{
		debug_msg("<expression has no value>\n");
		}

	return 1;
	}