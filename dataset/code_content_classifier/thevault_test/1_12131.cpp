ErrorEnum UpdateLocalHeader(AZ::IO::HandleType fileHandle, FileEntryBase* pFileEntry)
    {

        if (!AZ::IO::FileIOBase::GetDirectInstance()->Seek(fileHandle, pFileEntry->nFileHeaderOffset, AZ::IO::SeekType::SeekFromStart))
        {
            return ZD_ERROR_IO_FAILED;
        }

        ZipFile::LocalFileHeader header;
        if (!AZ::IO::FileIOBase::GetDirectInstance()->Read(fileHandle, &header, sizeof(header), true))
        {
            return ZD_ERROR_IO_FAILED;
        }

        AZ_Assert(header.lSignature == header.SIGNATURE, "header signature %u does not match signature %u", header.lSignature, header.SIGNATURE);

        header.desc.lCRC32 = pFileEntry->desc.lCRC32;
        header.desc.lSizeCompressed = pFileEntry->desc.lSizeCompressed;
        header.desc.lSizeUncompressed = pFileEntry->desc.lSizeUncompressed;
        header.nMethod = pFileEntry->nMethod;
        header.nFlags &= ~ZipFile::GPF_ENCRYPTED; // we don't support encrypted files

        if (!AZ::IO::FileIOBase::GetDirectInstance()->Seek(fileHandle, pFileEntry->nFileHeaderOffset, AZ::IO::SeekType::SeekFromStart))
        {
            return ZD_ERROR_IO_FAILED;
        }

        if (!AZ::IO::FileIOBase::GetDirectInstance()->Write(fileHandle, &header, sizeof(header)))
        {
            return ZD_ERROR_IO_FAILED;
        }

        return ZD_ERROR_SUCCESS;
    }