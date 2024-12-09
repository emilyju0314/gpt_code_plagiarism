bool Section::ReadFile(
    const std::string&    docFilename,      // [in] File name of parent document
    const std::string&    fileName,         // [in] File name
    bool                  isBinary,         // Whether file is SPIRV binary file
    std::vector<uint8_t>* pBinaryData,      // [out] Binary data
    std::string*          pTextData,        // [out] Text data
    std::string*          pErrorMsg)        // [out] Error message
{
    bool result = true;

    // Prepend directory from "docFilename" to the given filename.
    std::string path;
    auto separatorIndex = docFilename.find_last_of("/\\");
    if (separatorIndex != std::string::npos)
    {
        path = docFilename.substr(0, separatorIndex + 1);
    }
    path += fileName;

    // Open file
    FILE* pInFile = fopen(path.c_str(), isBinary ? "rb" : "r");
    if (pInFile == nullptr)
    {
        PARSE_ERROR(*pErrorMsg, 0, "Fails to open input file: %s\n", path.c_str());
        return false;
    }

    // Get file size
    fseek(pInFile, 0, SEEK_END);
    size_t fileSize = ftell(pInFile);
    fseek(pInFile, 0, SEEK_SET);

    // Allocate temp buffer and read file
    char* pData = new char[fileSize + 1];
    VFX_ASSERT(pData != nullptr);
    memset(pData, 0, fileSize + 1);
    size_t readSize = fread(pData, 1, fileSize, pInFile);

    // Copy to destination
    if (isBinary)
    {
        (*pBinaryData).resize(readSize);
        memcpy(&(*pBinaryData)[0], pData, readSize);
    }
    else
    {
        *pTextData = pData;
    }

    // Clean up
    delete[] pData;
    fclose(pInFile);

    return result;
}