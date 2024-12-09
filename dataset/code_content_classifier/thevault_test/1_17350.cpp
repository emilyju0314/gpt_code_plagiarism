void Provider::init(const string &fileName, const string &propertyString) {
	initComplete(fiftyoneDegreesInitProviderWithPropertyString(
        fileName.c_str(),
		&provider,
		propertyString.c_str()),
        fileName);
}