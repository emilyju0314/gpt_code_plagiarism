void Provider::initComplete(
		fiftyoneDegreesDataSetInitStatus initStatus,
		const string &fileName) {
	if (initStatus != DATA_SET_INIT_STATUS_SUCCESS)	{
		initException(initStatus, fileName);
	}
	else {
		initAvailableproperties();
		initHttpHeaders();
	}
}