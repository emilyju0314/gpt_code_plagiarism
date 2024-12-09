void CZIPIO::putZip64ExtendedInfoExtraField(Zip64ExtendedInfoExtraField &extendedInfo, std::vector<std::uint8_t> &info)
    {
        std::uint16_t fieldSize = 0;
        info.clear();
        if (fieldRequires64bits(extendedInfo.originalSize))
        {
            fieldSize += sizeof(std::uint64_t); // Store sizes as a pair.
            fieldSize += sizeof(std::uint64_t);
        }
        if (fieldRequires64bits(extendedInfo.fileHeaderOffset))
        {
            fieldSize += sizeof(std::uint64_t);
        }
        if (fieldRequires32bits(extendedInfo.diskNo))
        {
            fieldSize += sizeof(std::uint32_t);
        }
        putField(extendedInfo.signature, info);
        putField(fieldSize, info);
        if (fieldRequires64bits(extendedInfo.originalSize))
        {
            putField(extendedInfo.originalSize, info);
            putField(extendedInfo.compressedSize, info);
        }
        if (fieldRequires64bits(extendedInfo.fileHeaderOffset))
        {
            putField(extendedInfo.fileHeaderOffset, info);
        }
        if (fieldRequires32bits(extendedInfo.diskNo))
        {
            putField(extendedInfo.diskNo, info);
        }
    }