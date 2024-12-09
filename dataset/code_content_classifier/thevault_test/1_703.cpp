string NyxCmdBatteryRead::resolveArguments(int argc, char **argv)
{
	string retVal;

	if (optind < argc)
	{
		retVal = argv[optind++];
	}
	else
	{
		cerr << "Error: Not enough arguments" << endl;
	}

	return retVal;
}