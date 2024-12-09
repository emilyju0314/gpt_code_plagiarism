NyxCmdCommand *NyxCmdDeviceInfo::getCommand(string commandName)
{
	if (commandName == "query")
	{
		return new NyxCmdDeviceInfoQuery();
	}

	return NULL;
}