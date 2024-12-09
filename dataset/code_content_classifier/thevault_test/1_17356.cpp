string Provider::getDataSetPublishedDate() {
    stringstream stream;
	stream << provider.active->dataSet->header.published.year << "-"
		<< (int)provider.active->dataSet->header.published.month << "-"
		<< (int)provider.active->dataSet->header.published.day;
	return stream.str();
}