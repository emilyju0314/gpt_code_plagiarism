void ArchiveFileIO::SetAlias(const char* alias, const char* path)
    {
        FileIOBase* realUnderlyingFileIO = FileIOBase::GetDirectInstance();
        if (!realUnderlyingFileIO)
        {
            return;
        }
        realUnderlyingFileIO->SetAlias(alias, path);
    }