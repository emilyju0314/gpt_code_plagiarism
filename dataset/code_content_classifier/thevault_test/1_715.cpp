int NyxCmdDeviceType::executeCommand(const char *deviceId, int argc,
                                     char **argv)
{
	int err = -1;
	char *command = resolveArguments(argc, argv);

	if (command != NULL)
	{
		NyxCmdCommand *targetCommand = getCommand(command);

		if (targetCommand)
		{
			err = targetCommand->Execute(deviceId, argc, argv);
			delete targetCommand;
		}
		else
		{
			cout << "Error: Unknown command" << endl;
		}
	}
	else
	{
		throw (1);
	}

	return err;
}