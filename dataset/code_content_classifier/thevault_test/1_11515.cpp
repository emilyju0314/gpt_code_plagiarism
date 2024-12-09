void CZIP::addFileHeaderAndContents(const std::string &fileName, const std::string &zippedFileName)
    {
        LocalFileHeader fileHeader;
        CentralDirectoryFileHeader directoryEntry;
        Zip64ExtendedInfoExtraField info;
        bool bZIP64 = false;
        // Work from extended information 64 bit sizes
        info.fileHeaderOffset = m_offsetToEndOfLocalFileHeaders;
        info.originalSize = getFileSize(fileName);
        info.compressedSize = info.originalSize;
        // Save filename details
        directoryEntry.fileName = zippedFileName;
        directoryEntry.fileNameLength = directoryEntry.fileName.length();
        // If current offset > 32 bits use ZIP64
        if (fieldRequires64bits(info.fileHeaderOffset))
        {
            directoryEntry.fileHeaderOffset = static_cast<std::uint32_t>(~0);
            bZIP64 = true;
        }
        else
        {
            directoryEntry.fileHeaderOffset = info.fileHeaderOffset;
        }
        // File size > 32 bits then use ZIP64
        if (fieldRequires64bits(info.originalSize))
        {
            directoryEntry.uncompressedSize = static_cast<std::uint32_t>(~0);
            directoryEntry.compressedSize = static_cast<std::uint32_t>(~0);
            bZIP64 = true;
        }
        else
        {
            directoryEntry.uncompressedSize = info.originalSize;
            directoryEntry.compressedSize = info.compressedSize;
        }
        // Get file modified time and attributes.
        std::pair<std::uint16_t, std::uint16_t> modification = getFileModificationDateTime(fileName);
        directoryEntry.modificationDate = modification.first;
        directoryEntry.modificationTime = modification.second;
        directoryEntry.externalFileAttrib = getFileAttributes(fileName);
        // File is a directory so add trailing delimeter, set no compression and extractor version  1.0
        if (S_ISDIR(directoryEntry.externalFileAttrib >> 16))
        {
            if (directoryEntry.fileName.back() != '/')
            {
                directoryEntry.fileName.push_back('/');
                directoryEntry.fileNameLength++;
            }
            directoryEntry.extractorVersion = kZIPVersion10;
            directoryEntry.creatorVersion = (kZIPCreatorUnix << 8) | kZIPVersion10;
            directoryEntry.compression = kZIPCompressionStore;
        }
        // > 4 GB Files so ZIP64. Values not able to be stored in 32 bits have
        // there fields set to all ones and values placed in the extended
        // information field where their format has more bits.
        if (bZIP64)
        {
            m_ZIP64 = true;
            directoryEntry.extractorVersion = kZIPVersion45;
            directoryEntry.creatorVersion = (kZIPCreatorUnix << 8) | (kZIPVersion45);
            putZip64ExtendedInfoExtraField(info, directoryEntry.extraField);
            directoryEntry.extraFieldLength = directoryEntry.extraField.size();
        }
        // Copy information for file header and write to disk
        fileHeader.creatorVersion = directoryEntry.creatorVersion;
        fileHeader.bitFlag = directoryEntry.bitFlag;
        fileHeader.compression = directoryEntry.compression;
        fileHeader.modificationTime = directoryEntry.modificationTime;
        fileHeader.modificationDate = directoryEntry.modificationDate;
        fileHeader.uncompressedSize = directoryEntry.uncompressedSize;
        fileHeader.compressedSize = directoryEntry.compressedSize;
        fileHeader.fileNameLength = directoryEntry.fileNameLength;
        fileHeader.extraFieldLength = directoryEntry.extraFieldLength;
        fileHeader.fileName = directoryEntry.fileName;
        fileHeader.extraField = directoryEntry.extraField;
        positionInZIPFile(m_offsetToEndOfLocalFileHeaders);
        putZIPRecord(fileHeader);
        // Write any file contents next
        if (info.originalSize)
        {
            // Calculate files compressed size while deflating it and then either modify its
            // Local File Header record to have the correct compressed size and CRC or if its
            // compressed size is greater then or equal to its original size then store file
            // instead of compress.
            std::pair<std::uint32_t, std::int64_t> deflateValues = deflateFile(fileName, info.originalSize);
            fileHeader.crc32 = directoryEntry.crc32 = deflateValues.first;
            info.compressedSize = deflateValues.second;
            // Save away current position next file header
            m_offsetToEndOfLocalFileHeaders = currentPositionZIPFile();
            // Back up to beginning of current local file header
            positionInZIPFile(info.fileHeaderOffset);
            // Rewrite local file header with compressed size if compressed file
            // smaller or if ZIP64 format.
            if ((info.compressedSize < info.originalSize) || bZIP64)
            {
                if (bZIP64)
                {
                    putZip64ExtendedInfoExtraField(info, directoryEntry.extraField);
                    fileHeader.extraField = directoryEntry.extraField;
                }
                else
                {
                    fileHeader.compressedSize = directoryEntry.compressedSize = info.compressedSize;
                }
                putZIPRecord(fileHeader);
            }
            else
            {
                // Store non-compressed file.
                directoryEntry.extractorVersion = kZIPVersion10;
                fileHeader.creatorVersion = (kZIPCreatorUnix << 8) | kZIPVersion10;
                fileHeader.compression = directoryEntry.compression = kZIPCompressionStore;
                fileHeader.compressedSize = directoryEntry.compressedSize = info.originalSize;
                putZIPRecord(fileHeader);
                storeFile(fileName, info.originalSize);
                m_offsetToEndOfLocalFileHeaders = currentPositionZIPFile();
            }
        }
        else
        {
            m_offsetToEndOfLocalFileHeaders = currentPositionZIPFile();
        }
        // Save Central Directory File Entry
        m_zipCentralDirectory.push_back(directoryEntry);
        m_modified = true;
    }