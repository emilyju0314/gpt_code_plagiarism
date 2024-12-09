string Provider::getDataSetFormat() {
	stringstream stream;
	stream << fiftyoneDegreesGetDataSetFormat(provider.active->dataSet);
	return stream.str();
}