bool FileAppConfigLoader::LoadFileAppConfigConstants(FileAppConfigContainer& fileAppConfigContainer) {
    FileAppConfigErrorState fileAppConfigErrorState = loadFileAppConfigConstants(fileAppConfigContainer);
    bool result = false;
    if (fileAppConfigErrorState == FileAppConfigErrorState_NoError) {
        result = true;
    } else {
        std::string errorText = "ERROR while loading application configuration data from external file: ";
        if (fileAppConfigErrorState == FileAppConfigErrorState_FileOpenError) {
            errorText.append("File open error.");
            result = false;
        } else if (fileAppConfigErrorState == FileAppConfigErrorState_NotEqualsConstantsDeclsAndDefsCount) {
            errorText.append("Not equals count of constant declarations and initializations.");
            result = false;
        } else if (fileAppConfigErrorState == FileAppConfigErrorState_NoTypeForConstant) {
            errorText.append("There is no type for constant.");
            result = false;
        } else if (fileAppConfigErrorState == FileAppConfigErrorState_TypeNotMatchingDeclaration) {
            errorText.append("Type in initialization is not matching type in declaration.");
            result = false;
        } else if (fileAppConfigErrorState == FileAppConfigErrorState_NoNameForConstant) {
            errorText.append("There is no name for constant.");
            result = false;
        } else if (fileAppConfigErrorState == FileAppConfigErrorState_NoValueForConstant) {
            errorText.append("There is no value for constant.");
            result = false;
        } else if (fileAppConfigErrorState == FileAppConfigErrorState_NameNotMatchingDeclaration) {
            errorText.append("Name in file with constants initializations not matching name in file with constants declarations.");
            result = false;
        } else if (fileAppConfigErrorState == FileAppConfigErrorState_ConstantWrongValue) {
            errorText.append("ERROR: File open error.");
            result = false;
        } else {
            // Unknown error.
            errorText.append("Unknown error.");
            result = false;
        }
        LOG_ERROR(errorText);
    }

	result = checkLoadedValuesCorrectness(fileAppConfigContainer);
	return result;
}