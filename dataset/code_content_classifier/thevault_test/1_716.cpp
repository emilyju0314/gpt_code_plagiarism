char *NyxCmdDeviceType::resolveArguments(int argc, char **argv)
{
	char *commandStr = NULL;
	//Check that there are arguments left

	if (optind < argc)
	{
		//Command
		commandStr = argv[optind++];
	}

	return commandStr;
}