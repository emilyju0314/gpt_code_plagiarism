ErrorEnum WriteLocalHeader(AZ::IO::HandleType fileHandle, FileEntryBase* pFileEntry, AZStd::string_view szRelativePath)
    {
        size_t nFileNameLength = szRelativePath.size();
        size_t nHeaderSize = sizeof(ZipFile::LocalFileHeader) + nFileNameLength;

        pFileEntry->nFileDataOffset = aznumeric_cast<uint32_t>(pFileEntry->nFileHeaderOffset + nHeaderSize);
        pFileEntry->nEOFOffset = pFileEntry->nFileDataOffset + pFileEntry->desc.lSizeCompressed;

        if (!AZ::IO::FileIOBase::GetDirectInstance()->Seek(fileHandle, pFileEntry->nFileHeaderOffset, AZ::IO::SeekType::SeekFromStart))
        {
            return ZD_ERROR_IO_FAILED;
        }

        ZipFile::LocalFileHeader header;
        header.lSignature = ZipFile::LocalFileHeader::SIGNATURE;
        header.nVersionNeeded = 10;
        header.nFlags = 0;
        header.nMethod = pFileEntry->nMethod;
        header.nLastModDate = pFileEntry->nLastModDate;
        header.nLastModTime = pFileEntry->nLastModTime;
        header.desc = pFileEntry->desc;
        header.nFileNameLength = aznumeric_cast<uint16_t>(nFileNameLength);
        header.nExtraFieldLength = 0;

        if (!AZ::IO::FileIOBase::GetDirectInstance()->Write(fileHandle, &header, sizeof(header)))
        {
            return ZD_ERROR_IO_FAILED;
        }

        if (nFileNameLength > 0)
        {
            if (!AZ::IO::FileIOBase::GetDirectInstance()->Write(fileHandle, szRelativePath.data(), nFileNameLength))
            {
                return ZD_ERROR_IO_FAILED;
            }
        }

        return ZD_ERROR_SUCCESS;
    }