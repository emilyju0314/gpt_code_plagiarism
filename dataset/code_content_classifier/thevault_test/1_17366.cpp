void Provider::reloadFromFile() {
	fiftyoneDegreesDataSetInitStatus initStatus = 
		fiftyoneDegreesProviderReloadFromFile(&provider);
	if (initStatus != DATA_SET_INIT_STATUS_SUCCESS) {
		initException(initStatus, provider.active->dataSet->fileName);
	}
}