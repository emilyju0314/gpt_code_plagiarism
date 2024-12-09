void CacheFactory::AddFileEntry(char* strFilePath, const ZipFile::CDRFileHeader* pFileHeader, const SExtraZipFileData& extra)
    {
        if (pFileHeader->lLocalHeaderOffset > m_CDREnd.lCDROffset)
        {
            AZ_Warning("Archive", false, "ZD_ERROR_CDR_IS_CORRUPT:"
                " Central Directory contains file descriptors pointing outside the archive file boundaries."
                " The archive file is either truncated or damaged.Please try to repair the file"); // the file offset is beyond the CDR: impossible
            return;
        }

        if ((pFileHeader->nMethod == ZipFile::METHOD_STORE || pFileHeader->nMethod == ZipFile::METHOD_STORE_AND_STREAMCIPHER_KEYTABLE) && pFileHeader->desc.lSizeUncompressed != pFileHeader->desc.lSizeCompressed)
        {
            AZ_Warning("Archive", false, "ZD_ERROR_VALIDATION_FAILED:"
                " File with STORE compression method declares its compressed size not matching its uncompressed size."
                " File descriptor is inconsistent, archive content may be damaged, please try to repair the archive");
            return;
        }

        FileEntryBase fileEntry(*pFileHeader, extra);

        InitDataOffset(fileEntry, pFileHeader);

        if (m_bBuildFileEntryMap)
        {
            m_mapFileEntries.emplace(strFilePath, fileEntry);
        }

        if (m_bBuildFileEntryTree)
        {
            m_treeFileEntries.Add(strFilePath, fileEntry);
        }
    }