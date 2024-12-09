bool CZIP::isDirectory(const CZIP::FileDetail &fileEntry)
    {
        return ((fileEntry.externalFileAttrib & 0x10) ||
                (S_ISDIR(fileEntry.externalFileAttrib >> 16)));
    }