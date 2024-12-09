string Provider::getDataSetName() {
    stringstream stream;
	stream << fiftyoneDegreesGetDataSetName(provider.active->dataSet);
    return stream.str();
}