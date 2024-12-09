uint8_t FileBrowser::onClick(uint8_t fileIndex, uint8_t (&refScene)[MAX_LIGHT_STEPS][NUM_MUGS], uint8_t &refNumSteps, char (&refCurrentSetting)[STRING_LENGTH]) {
	//Open clicked file/directory
	if(!FILE.open(CURRENT_FILE_LIST[fileIndex], O_READ)) {
		error("Opening file failed");
		return 0;
	}
	
	//If clicked on dir call change directory function
	if(FILE.isDir()) {
		FILE.close();
		if(!changeDir(CURRENT_FILE_LIST[fileIndex])) {
			error("Opening folder failed");
			return 0;
		}
		pageIndex = 0;
		return 2;
	}
	//If clicked on a file call extractScene function
	else if (FILE.isFile()) {
		bool errorFlag = extractScene(refScene,refNumSteps,refCurrentSetting);
		FILE.close();
		return errorFlag;
	}
	else {
		FILE.close();
		return 0;
	}
}