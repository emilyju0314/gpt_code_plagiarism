NyxCmdCommand *NyxCmdBattery::getCommand(string commandName)
{
	if (commandName == "readall")
	{
		return new NyxCmdBatteryRead();
	}
	else if (commandName == "register_status")
	{
		return new NyxCmdBatteryRegisterStatus();
	}

	return NULL;
}