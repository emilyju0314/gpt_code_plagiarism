int64_t Provider::initWithValidate(
	const string &fileName,
	const string &propertyString) {
	int64_t predictedSize;

	// Reset the actual size parameter as it is global and may have been set
	// before.
	_actualSize = 0;

	// Use the getProviderSize function to get the predicted size that the
	// provider will need.
	predictedSize = (int64_t)fiftyoneDegreesGetProviderSizeWithPropertyString(
		fileName.c_str(),
		propertyString.c_str());

	// Set the malloc function to use the function that increments _actualSize
	// by the amount being allocated.
	fiftyoneDegreesMalloc = validateMalloc;

	// Use the standard init function to initialise the provider. This is the
	// same function used by the standard constructor, however every memory
	// allocation will be counted using the validateMalloc function.
	init(fileName, propertyString);

	// Revert the malloc function so that future calls do not use the 
	// validateMalloc function.
	fiftyoneDegreesMalloc = malloc;

	// Return the difference between the predicted and actual sizes. A positive
	// number is an overestimate, and a negative number is an underestimate.
	return predictedSize - _actualSize;
}