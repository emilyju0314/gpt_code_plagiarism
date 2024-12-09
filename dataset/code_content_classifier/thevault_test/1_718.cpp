int NyxCmdQueryCommand::resolveArguments(int argc, char **argv)
{
	int retVal = RESOLVE_ARGS_INVALID;
	int c = 0;

	// reset errors and prevent from outputting
	opterr = 0;

	static struct option long_options[] =
	{
		{"format", required_argument, 0, 'f' },
		{"list", no_argument, 0, 'l' },
		{0, 0, 0, 0 }
	};

	while (1)
	{
		int option_index = 0;

		c = getopt_long(argc, argv, "lf:", long_options, &option_index);

		if (c == -1)
		{
			break;
		}

		switch (c)
		{
			// format is a long option only and in index 0
			case 'f':
				output = NyxCmdOutput::createNyxCmdOutput(optarg);

				if (NULL == output)
				{
					retVal = RESOLVE_ARGS_FAILED;
				}

				break;

			case 'l':
				retVal = RESOLVE_ARGS_LIST_ALL_QUERIES;
				break;

			// all that are not recognized make the function fail
			default:
				retVal = RESOLVE_ARGS_FAILED;
				break;
		}
	}

	if (RESOLVE_ARGS_INVALID == retVal)
	{
		// check if there is still arguments left
		// there wasn't so it's a query for all
		if (0 == (argc - optind))
		{
			retVal = RESOLVE_ARGS_EXECUTE_ALL_QUERIES;
		}
		else
		{
			retVal = optind;
		}
	}

	return retVal;
}