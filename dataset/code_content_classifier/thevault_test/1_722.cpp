string NyxCmdDeviceInfo::Usage()
{
	ostringstream usage;

	usage << "COMMAND" << endl;
	usage << left << "  " << setw(30) << "query [QUERY-OPTIONS] [QUERY]" << setw(
	          30) << "Query device information" << endl;
	usage << left << setw(32) << "" <<
	      "If [QUERY] not specified, returns all information" << endl;
	usage << "QUERY-OPTIONS" << endl;
	usage << left << "  " << setw(30) << "-f FORMAT, --format=FORMAT" << setw(
	          30) << "Set output format (e.g. -f json)" << endl;
	usage << left << setw(32) << "" << "json - output in 'JSON' format" << endl;
	usage << left << setw(32) << "" << "plain - output in 'plain' format" << endl;
	usage << left << setw(32) << "" << "shell - output in 'shell' format" << endl;
	usage << left << setw(32) << "" <<
	      "Defaults to 'plain' if 'format' option is left out" << endl;
	usage << left << "  " << setw(30) << "-l, --list" << setw(
	          30) << "List available command targets" << endl;
	usage << left << setw(32) << "" << "(e.g. nyx-cmd DeviceInfo query -l)" << endl;
	usage << "QUERY" << endl;

	//device_info query usage
	std::map<string, commandUsage> tempMap;
	nyx_device_type_t tempType;

	NyxCmdDeviceInfoQuery().initCommandMap(tempType, tempMap);

	for (std::map<string, commandUsage>::const_iterator itr = tempMap.begin();
	        itr != tempMap.end(); ++itr)
	{
		usage << left << "  " << setw(30) <<  itr->first << setw(
		          30) << itr->second.commandStr << endl;
	}

	return usage.str();
}