Provider::Provider(
	const string &fileName,
	const string &propertyString,
	bool validate) {
	stringstream message;
	int64_t difference;

	if (validate == true)
	{
		// Get the difference between the calculated memory needed and the
		// actual memory userd.
		difference = initWithValidate(fileName, propertyString);

		// If the calculated memory is less than the actual memory then throw
		// an error.
		// Note: this will always be a slight overestimate
		if (difference < 0) {
			message << "Predicted memory usage is below the actual usage by "
				<< (0 - difference)
				<< " bytes.";
			throw runtime_error(message.str());
		}
	}
	else {
		// Validate is false so divert to the standard constructor.
		Provider(fileName, propertyString);
	}
}