int NyxCmdQueryCommand::Execute(const char *deviceId, int argc, char **argv)
{
	nyx_error_t error = NYX_ERROR_GENERIC;

	// initialize output to NULL
	output = NULL;

	// initialize command specific enums and usage strings if it is empty
	if (commandMap.empty())
	{
		initCommandMap(nyxDevType, commandMap);
	}

	int argIndex = resolveArguments(argc, argv);

	// initialize a default output if not initialized from arguments
	if (NULL == output)
	{
		output = NyxCmdOutput::createNyxCmdOutput();
	}

	switch (argIndex)
	{
		case RESOLVE_ARGS_INVALID:
		case RESOLVE_ARGS_FAILED:
			cerr << "Error: Error resolving arguments" << endl;
			break;

		case RESOLVE_ARGS_LIST_ALL_QUERIES:
			listAllQueries();
			error = NYX_ERROR_NONE;
			break;

		case RESOLVE_ARGS_EXECUTE_ALL_QUERIES:
			error = executeQueries(deviceId, argIndex, argc, argv, true);
			break;

		default:
			error = executeQueries(deviceId, argIndex, argc, argv, false);
			break;
	}

	// clean up
	delete output;

	commandMap.clear();

	return (NYX_ERROR_NONE == error) ? 0 : -1;
}