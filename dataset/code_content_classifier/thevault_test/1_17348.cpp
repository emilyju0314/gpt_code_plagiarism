void Provider::initException(
		fiftyoneDegreesDataSetInitStatus initStatus,
		const string &fileName) {
	stringstream message;
	switch(initStatus) {
		case DATA_SET_INIT_STATUS_INSUFFICIENT_MEMORY:
			throw runtime_error("Insufficient memory allocated.");
			break;
		case DATA_SET_INIT_STATUS_CORRUPT_DATA:
			throw runtime_error("The data was not in the correct format. Check "
				"the data file is uncompressed.");
			break;
		case DATA_SET_INIT_STATUS_INCORRECT_VERSION:
			throw runtime_error("The data is an unsupported version. Check you "
				"have the latest data and API.");
			break;
		case DATA_SET_INIT_STATUS_FILE_NOT_FOUND:
			message << "The data file '" << fileName << "' could not be found. "
				"Check the file path and that the program has sufficient read "
				"permissions.";
			throw invalid_argument(message.str());
			break;
		case DATA_SET_INIT_STATUS_NULL_POINTER:
			throw runtime_error("Null pointer to the existing dataset or memory"
				" location.");
			break;
		case DATA_SET_INIT_STATUS_POINTER_OUT_OF_BOUNDS:
			throw runtime_error("Allocated continuous memory containing "
				"51Degrees data file appears to be smaller than expected. Most"
				" likely because the data file was not fully loaded into the "
				"allocated memory.");
			break;
		default:
		case DATA_SET_INIT_STATUS_NOT_SET:
			throw runtime_error("Could not create data set from file.");
			break;
	}
}