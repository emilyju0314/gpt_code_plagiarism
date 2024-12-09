void CacheFactory::InitDataOffset(FileEntryBase& fileEntry, const ZipFile::CDRFileHeader* pFileHeader)
    {
        if (m_encryptedHeaders != ZipFile::HEADERS_NOT_ENCRYPTED)
        {
            // use CDR instead of local header
            fileEntry.nFileDataOffset = pFileHeader->lLocalHeaderOffset + sizeof(ZipFile::LocalFileHeader) + pFileHeader->nFileNameLength + pFileHeader->nExtraFieldLength;
        }
        else
        {
            Seek(pFileHeader->lLocalHeaderOffset);

            // Read only the LocalFileHeader w/ no additional bytes ('name' or 'extra' fields)
            AZStd::vector<char> buffer;
            uint32_t bufferLen = sizeof(ZipFile::LocalFileHeader);
            buffer.resize_no_construct(bufferLen);
            Read(buffer.data(), bufferLen);

            const auto* localFileHeader = reinterpret_cast<const ZipFile::LocalFileHeader*>(buffer.data());

            // set the correct file data offset...
            fileEntry.nFileDataOffset = pFileHeader->lLocalHeaderOffset + sizeof(ZipFile::LocalFileHeader) +
                localFileHeader->nFileNameLength + localFileHeader->nExtraFieldLength;

            fileEntry.nEOFOffset = fileEntry.nFileDataOffset + fileEntry.desc.lSizeCompressed;

            if (m_nInitMethod != ZipDir::InitMethod::Default)
            {
                if (m_nInitMethod == ZipDir::InitMethod::FullValidation)
                {
                    // Mark the FileEntry to check CRC when the next read occurs
                    fileEntry.bCheckCRCNextRead = true;
                }

                // Timestamps
                if (pFileHeader->nLastModDate != localFileHeader->nLastModDate
                    || pFileHeader->nLastModTime != localFileHeader->nLastModTime)
                {
                    AZ_Warning("Archive", false, "ZD_ERROR_VALIDATION_FAILED: (%s)\n"
                        " The local file header's modification timestamps don't match that of the global file header in the archive."
                        " The archive timestamps are inconsistent and may be damaged. Check the archive file.", m_szFilename.c_str());
                    // don't return here, it may be ok.
                }

                // Validate data
                if (pFileHeader->desc != localFileHeader->desc  // this checks CRCs and compressed/uncompressed sizes
                    || pFileHeader->nMethod != localFileHeader->nMethod
                    || pFileHeader->nFileNameLength != localFileHeader->nFileNameLength)
                {
                    AZ_Warning("Archive", false, "ZD_ERROR_VALIDATION_FAILED: (%s)\n"
                        " The local file header descriptor doesn't match basic parameters declared in the global file header in the file."
                        " The archive content is inconsistent and may be damaged. Please try to repair the archive.", m_szFilename.c_str());
                    // return here because further checks aren't worse than this.
                    return;
                }

                // Read extra data
                uint32_t extraDataLen = localFileHeader->nFileNameLength + localFileHeader->nExtraFieldLength;
                buffer.resize_no_construct(buffer.size() + extraDataLen);
                Read(buffer.data() + buffer.size(), extraDataLen);

                // Compare local file name with the CDR file name, they should match
                AZStd::string_view zipFileName{ buffer.data() + sizeof(ZipFile::LocalFileHeader), localFileHeader->nFileNameLength };
                AZStd::string_view cdrFileName{ reinterpret_cast<const char*>(pFileHeader + 1), pFileHeader->nFileNameLength };
                if (zipFileName != cdrFileName)
                {
                    AZ_Warning("Archive", false, "ZD_ERROR_VALIDATION_FAILED: (%s)\n"
                        " The file name in the local file header doesn't match the name in the global file header."
                        " The archive content is inconsisten with the directory. Please check the archive.", m_szFilename.c_str());
                }

                // CDR and local "extra field" lengths may be different, should we compare them if they are equal?

                // make sure it's the same file and the fileEntry structure is properly initialized
                AZ_Assert(fileEntry.nFileHeaderOffset == pFileHeader->lLocalHeaderOffset,
                    "The file entry header offset doesn't match the file header local offst (%s)", m_szFilename.c_str());

                if (fileEntry.nFileDataOffset >= m_nCDREndPos)
                {
                    AZ_Warning("Archive", false, "ZD_ERROR_VALIDATION_FAILED: (%s)\n"
                        " The global file header declares the file which crosses the boundaries of the archive."
                        " The archive is either corrupted or truncated, please try to repair it", m_szFilename.c_str());
                }

                // End Validation
            }
        }
    }