string Provider::getDataSetNextUpdateDate() {
    stringstream stream;
	stream << provider.active->dataSet->header.nextUpdate.year << "-"
		<< (int)provider.active->dataSet->header.nextUpdate.month << "-"
		<< (int)provider.active->dataSet->header.nextUpdate.day;
    return stream.str();
}