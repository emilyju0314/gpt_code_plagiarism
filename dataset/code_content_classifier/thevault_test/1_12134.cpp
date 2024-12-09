void FileEntry::OnNewFileData(const void* pUncompressed, uint64_t nSize, uint64_t nCompressedSize, uint32_t nCompressionMethod, bool bContinuous)
    {
        time_t nTime;
        time(&nTime);
        tm t;
        azlocaltime(&nTime, &t);

        // While local time converts the month to a 0 to 11 interval...
        // ...the pack file expects months from 1 to 12...
        // Therefore, for correct date, we have to do t->tm_mon+=1;
        t.tm_mon += 1;

        this->nLastModTime = DOSTime(&t);
        this->nLastModDate = DOSDate(&t);

        if (!bContinuous)
        {
            this->desc.lSizeCompressed = aznumeric_cast<uint32_t>(nCompressedSize);
            this->desc.lSizeUncompressed = aznumeric_cast<uint32_t>(nSize);
        }

        // we'll need CRC32 of the file to pack it
        this->desc.lCRC32 = AZ::Crc32(pUncompressed, nSize);

        this->nMethod = static_cast<uint16_t>(nCompressionMethod);
    }