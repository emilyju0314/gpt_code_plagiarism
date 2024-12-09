void PathGroup::determinePathTravels(const char * inputFile) {
	int counter = 0;
	FILE * file;
	char buffer[100] = { 0 };
	int scanfError = 0;
	float targetX, targetY;

	file = fopen(inputFile, "r");
	while ((NULL != file) && (NULL != fgets(buffer, 99, file))
			&& (counter < MAX_NUM_PATH_TRAVELS)) {
		printf("%s", buffer);
		// parse informations from file
		scanfError = sscanf(buffer, "%f;%f", &targetX, &targetY);

		this->travels[counter] = new PathTravel(targetX, targetY, 0.0f);

		if (scanfError <= 0)
			break;

		counter++;
	}

	if (NULL != file) {
		fclose(file);
	}
}