nyx_error_t NyxCmdQueryCommand::executeQueries(const char *deviceId,
        int startIndex, int argc,
        char **argv,
        bool allQueries)
{
	nyx_device_handle_t device = NULL;
	nyx_os_info_query_t infoType;
	nyx_error_t error = NYX_ERROR_GENERIC;
	nyx_error_t finalError = NYX_ERROR_GENERIC;

	error = nyx_init();

	if (NYX_ERROR_NONE == error && NULL != output)
	{
		error = nyx_device_open(nyxDevType, deviceId, &device);

		if (NULL != device)
		{
			ostringstream outputStream;
			const char *retVal;
			bool keepPrinting = true;
			int failCount = 0;
			std::map<string, commandUsage>::const_iterator iter = commandMap.begin();

			if (allQueries)
			{
				output->printErrorEnabled = false;
			}

			output->beginOutput(outputStream);

			while (keepPrinting)
			{
				// 'allQueries' controls how the iterator is fetched
				// when it's false then you find the iterator based on strings
				if (false == allQueries)
				{
					iter = commandMap.find(string(argv[startIndex++]));

					// when there is no more arguments, stop printing
					if (0 == (argc - startIndex))
					{
						keepPrinting = false;
					}
				}

				if (commandMap.end() != iter)
				{
					error = nyxQuery(device, iter->second.commandEnum, &retVal);

					switch (error)
					{
						case NYX_ERROR_NONE:
							output->printOutput(outputStream, iter->first, retVal);
							finalError = NYX_ERROR_NONE;
							break;

						case NYX_ERROR_NOT_IMPLEMENTED:
							output->printError(outputStream, "Error: Query not implemented");
							break;

						case NYX_ERROR_DEVICE_UNAVAILABLE:
							output->printError(outputStream, "Error: Device or value not available");
							break;

						default:
							ostringstream tempError;
							tempError << "Error: Error " << error << " in executing query";
							output->printError(outputStream, tempError.str());
							break;
					}

					// when 'allQueries' is true, iterator is looped
					if (allQueries)
					{
						// stop outputting if final
						if (commandMap.end() == ++iter)
						{
							keepPrinting = false;
						}
					}
				}
				else
				{
					if (false == allQueries)
						// increment failcount for all other cases than 'query all'
					{
						failCount++;
					}
				}
			}

			// don't finalize output if there wasn't even one successful query
			if (NYX_ERROR_NONE == finalError)
			{
				output->finalizeOutput(outputStream);
			}

			// if there were queries that were not found print the
			// number of failed queries
			// NOTE: this is not printed when doing 'query all'
			if (failCount)
			{
				cerr << "Error: " << failCount << " query/queries not found" << endl;
			}

			nyx_device_close(device);
		}
	}
	else
	{
		cerr << "Error: Error initializing Nyx" << endl;
	}

	nyx_deinit();

	return finalError;
}