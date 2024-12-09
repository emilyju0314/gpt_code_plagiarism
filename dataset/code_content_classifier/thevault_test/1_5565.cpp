int filenameOperations::convertFile() {
	
	std::cout << "Reading File..." << std::endl;

	if (extension == "bmp") {
		return cv::COLOR_RGB2GRAY;
	}
	else if (extension == "png") {
		return cv::COLOR_RGB2GRAY;
	}
	else if (extension == "jpg") {
		return cv::COLOR_RGB2GRAY;
	}
	else {
		std::cout << "No file conversions... file not proper type... try again." << std::endl;
		//exit(EXIT_SUCCESS);
	}
}