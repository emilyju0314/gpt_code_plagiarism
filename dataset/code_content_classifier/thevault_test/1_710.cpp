NyxCmdCommand *NyxCmdKeys::getCommand(string commandName)
{
	if (commandName == "subscribe_key_event")
	{
		return new NyxCmdKeysEvents(NYX_DEVICE_KEYS);
	}

	if (commandName == "subscribe_power_key_event")
	{
		return new NyxCmdKeysEvents(NYX_DEVICE_POWERKEY);
	}

	return NULL;
}