static HRESULT FileToBlob(char const* pFileName, ID3DBlob** blob)
{
    std::FILE* file = std::fopen(pFileName, "rb");
    if (!file) return HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);

    if(fseek(file, 0, SEEK_END) != 0) { std::fclose(file); return HRESULT_FROM_WIN32(ERROR_SEEK); }

    long fileSize = std::ftell(file);
    if (fileSize == -1) return HRESULT_FROM_WIN32(_doserrno);

    HRESULT res = NO_ERROR;
    if (FAILED(res = D3DCreateBlob((size_t)fileSize, blob))) { std::fclose(file); return res; }

    std::rewind(file);

    long readResult = (long)std::fread((*blob)->GetBufferPointer(), 1, (*blob)->GetBufferSize(), file);
    if (readResult != fileSize) { std::fclose(file); return HRESULT_FROM_WIN32(ERROR_READ_FAULT); }

    return true;
}