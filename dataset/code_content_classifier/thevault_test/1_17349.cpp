void Provider::init(const string &fileName) {
	initComplete(fiftyoneDegreesInitProviderWithPropertyString(
        fileName.c_str(),
		&provider,
        NULL),
        fileName);
}