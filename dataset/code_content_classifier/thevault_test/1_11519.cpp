bool CZIP::extract(const std::string &fileName, const std::string &destFileName)
    {
        bool fileExtracted = false;
        if (!m_open)
        {
            throw Exception("ZIP archive has not been opened.");
        }
        for (auto &directoryEntry : m_zipCentralDirectory)
        {
            if (directoryEntry.fileName.compare(fileName) == 0)
            {
                Zip64ExtendedInfoExtraField extendedInfo;
                LocalFileHeader fileHeader;
                std::uint32_t crc32;
                // Set up 64 bit data values if needed
                extendedInfo.compressedSize = directoryEntry.compressedSize;
                extendedInfo.originalSize = directoryEntry.uncompressedSize;
                extendedInfo.fileHeaderOffset = directoryEntry.fileHeaderOffset;
                // If dealing with ZIP64 extract full 64 bit values from extended field
                if (fieldOverflow(directoryEntry.compressedSize) ||
                    fieldOverflow(directoryEntry.uncompressedSize) ||
                    fieldOverflow(directoryEntry.fileHeaderOffset))
                {
                    getZip64ExtendedInfoExtraField(extendedInfo, directoryEntry.extraField);
                }
                // Move to and read file header
                positionInZIPFile(extendedInfo.fileHeaderOffset);
                getZIPRecord(fileHeader);
                // Now positioned at file contents so extract
                if (directoryEntry.compression == kZIPCompressionDeflate)
                {
                    crc32 = inflateFile(destFileName, extendedInfo.compressedSize);
                    fileExtracted = true;
                }
                else if (directoryEntry.compression == kZIPCompressionStore)
                {
                    crc32 = extractFile(destFileName, extendedInfo.originalSize);
                    fileExtracted = true;
                }
                else
                {
                    throw Exception("File uses unsupported compression = " + std::to_string(directoryEntry.compression));
                }
                // Check file CRC32
                if (crc32 != directoryEntry.crc32)
                {
                    throw Exception("File " + destFileName + " has an invalid CRC.");
                }
                break;
            }
        }
        return (fileExtracted);
    }