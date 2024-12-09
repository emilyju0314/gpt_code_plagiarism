void filenameOperations::parseFilename() {

	std::vector<std::string> arr = split_string(fullPath, '/');
	int arrSize = arr.size();
	
	//we now have all of our arguments, need to find the extension of the last one now.
	std::vector<std::string> extensionArr = split_string(arr[arrSize - 1], '.');
	filename = extensionArr[0];
	extension = extensionArr[1];
	printf("Reading image file type: %s\n", extension);
}