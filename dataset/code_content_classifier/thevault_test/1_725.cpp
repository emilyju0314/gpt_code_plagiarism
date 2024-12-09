nyx_system_erase_type_t NyxCmdSystemErase::resolveArguments(int argc,
        char **argv)
{
	// No default is allowed given the nature of the command
	nyx_system_erase_type_t retVal = (nyx_system_erase_type_t) - 1;

	if (optind < argc)
	{
		//Arguments
		char *argumentStr = argv[optind++];

		if (strcmp(argumentStr, "var") == 0)
		{
			retVal = NYX_SYSTEM_ERASE_VAR;
		}
		else if (strcmp(argumentStr, "media") == 0)
		{
			retVal = NYX_SYSTEM_ERASE_MEDIA;
		}
		else if (strcmp(argumentStr, "all") == 0)
		{
			retVal = NYX_SYSTEM_ERASE_ALL;
		}
		else if (strcmp(argumentStr, "developer") == 0)
		{
			retVal = NYX_SYSTEM_ERASE_DEVELOPER;
		}
		else
		{
			cerr << "Error: Unknown argument - " << argumentStr << endl;
		}
	}
	else
	{
		cerr << "Error: No default value is defined" << endl;
	}

	return retVal;
}