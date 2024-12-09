static crn_uint8* read_file_into_buffer(const char* pFilename, crn_uint32& size)
{
    size = 0;

    FILE* pFile = nullptr;
    fopen_s(&pFile, pFilename, "rb");
    if (!pFile)
        return nullptr;

    fseek(pFile, 0, SEEK_END);
    size = ftell(pFile);
    fseek(pFile, 0, SEEK_SET);

    crn_uint8* pSrc_file_data = static_cast<crn_uint8*>(malloc(std::max(1U, size)));
    if ((!pSrc_file_data) || (fread(pSrc_file_data, size, 1, pFile) != 1))
    {
        fclose(pFile);
        free(pSrc_file_data);
        size = 0;
        return nullptr;
    }

    fclose(pFile);
    return pSrc_file_data;
}