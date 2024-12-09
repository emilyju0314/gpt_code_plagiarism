NyxCmdCommand *NyxCmdCharger::getCommand(string commandName)
{
	if (commandName == "query")
	{
		return new NyxCmdChargerQuery();
	}
	else if (commandName == "register")
	{
		return new NyxCmdChargerRegister();
	}

	return NULL;
}