ErrorEnum Refresh(CZipFile* f, FileEntryBase* pFileEntry)
    {
        if (pFileEntry->nFileDataOffset != pFileEntry->INVALID_DATA_OFFSET)
        {
            return ZD_ERROR_SUCCESS;
        }

        if (FSeek(f, pFileEntry->nFileHeaderOffset, SEEK_SET))
        {
            return ZD_ERROR_IO_FAILED;
        }

        // No validation in release or profile!

        // read the local file header and the name (for validation) into the buffer
        ZipFile::LocalFileHeader fileHeader;
        //if (1 != fread (&fileHeader, sizeof(fileHeader), 1, f))
        if (1 != FRead(f, &fileHeader, sizeof(fileHeader), 1))
        {
            return ZD_ERROR_IO_FAILED;
        }

        if (fileHeader.desc != pFileEntry->desc
            || fileHeader.nMethod != pFileEntry->nMethod)
        {
            AZ_Fatal("Pak", "ERROR: File header doesn't match previously cached file entry record (%s) \n fileheader desc=(%d,%d,%d), method=%d, \n fileentry desc=(%d,%d,%d),method=%d",
                "Unknown" /*f->_tmpfname*/,
                fileHeader.desc.lCRC32, fileHeader.desc.lSizeCompressed, fileHeader.desc.lSizeUncompressed,
                fileHeader.nMethod,
                pFileEntry->desc.lCRC32, pFileEntry->desc.lSizeCompressed, pFileEntry->desc.lSizeUncompressed,
                pFileEntry->nMethod);

            return ZD_ERROR_IO_FAILED;
            //CryFatalError(szErrDesc);
            //THROW_ZIPDIR_ERROR(ZD_ERROR_VALIDATION_FAILED,szErrDesc);
        }
        pFileEntry->nFileDataOffset = pFileEntry->nFileHeaderOffset + sizeof(ZipFile::LocalFileHeader) + fileHeader.nFileNameLength + fileHeader.nExtraFieldLength;
        pFileEntry->nEOFOffset = pFileEntry->nFileDataOffset + pFileEntry->desc.lSizeCompressed;


        return ZD_ERROR_SUCCESS;
    }