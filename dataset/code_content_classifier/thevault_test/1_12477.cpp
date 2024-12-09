bool CacheFactory::Prepare()
    {
        if (!FindCDREnd())
        {
            return false;
        }

        //Earlier pak file encryption techniques stored the encryption type in the disk number of the CDREnd.
        //This works, but can't be used by the more recent techniques that require signed paks to be readable by 7-Zip during dev.
        ZipFile::EHeaderEncryptionType headerEnc = (ZipFile::EHeaderEncryptionType)((m_CDREnd.nDisk & 0xC000) >> 14);
        if (headerEnc == ZipFile::HEADERS_ENCRYPTED_TEA || headerEnc == ZipFile::HEADERS_ENCRYPTED_STREAMCIPHER)
        {
            m_encryptedHeaders = headerEnc;
        }
        m_CDREnd.nDisk = m_CDREnd.nDisk & 0x3fff;

        //Pak may be encrypted with CryCustom technique and/or signed. Being signed is compatible (in principle) with the earlier encryption methods.
        //The information for this exists in some custom headers at the end of the archive (in the comment section)
        if (m_CDREnd.nCommentLength >= sizeof(m_headerExtended))
        {
            Seek(m_CDREnd.lCDROffset + m_CDREnd.lCDRSize + sizeof(ZipFile::CDREnd));
            Read(&m_headerExtended, sizeof(m_headerExtended));
            if (m_headerExtended.nHeaderSize != sizeof(m_headerExtended))
            {
                // Extended Header is not valid
                AZ_Warning("Archive", false, "ZD_ERROR_DATA_IS_CORRUPT: Bad extended header");
                return false;
            }
            //We have the header, so read the encryption and signing techniques
            m_signedHeaders = (ZipFile::EHeaderSignatureType)m_headerExtended.nSigning;

            //Prepare for a quick sanity check on the size of the comment field now that we know what it should contain
            //Also check that the techniques are supported
            uint16_t expectedCommentLength = sizeof(m_headerExtended);

            if (m_headerExtended.nEncryption != ZipFile::HEADERS_NOT_ENCRYPTED && m_encryptedHeaders != ZipFile::HEADERS_NOT_ENCRYPTED)
            {
                //Encryption technique has been specified in both the disk number (old technique) and the custom header (new technique).
                AZ_Warning("Archive", false, "ZD_ERROR_DATA_IS_CORRUPT: Unexpected encryption technique in header");
                return false;
            }
            else
            {
                //The encryption technique has been specified only in the custom header
                m_encryptedHeaders = (ZipFile::EHeaderEncryptionType)m_headerExtended.nEncryption;
                switch (m_encryptedHeaders)
                {
                case ZipFile::HEADERS_NOT_ENCRYPTED:
                    break;
                case ZipFile::HEADERS_ENCRYPTED_STREAMCIPHER_KEYTABLE:
                    expectedCommentLength += sizeof(ZipFile::CryCustomEncryptionHeader);
                    break;
                default:
                    // Unexpected technique
                    AZ_Warning("Archive", false, "ZD_ERROR_DATA_IS_CORRUPT: Bad encryption technique in header");
                    return false;
                }
            }

            //Add the signature header to the expected size
            switch (m_signedHeaders)
            {
            case ZipFile::HEADERS_NOT_SIGNED:
                break;
            case ZipFile::HEADERS_CDR_SIGNED:
                expectedCommentLength += sizeof(ZipFile::CrySignedCDRHeader);
                break;
            default:
                // Unexpected technique
                AZ_Warning("Archive", false, "ZD_ERROR_DATA_IS_CORRUPT: Bad signing technique in header");
                return false;
            }

            if (m_CDREnd.nCommentLength == expectedCommentLength)
            {
                if (m_signedHeaders == ZipFile::HEADERS_CDR_SIGNED)
                {
                    Read(&m_headerSignature, sizeof(m_headerSignature));
                    if (m_headerSignature.nHeaderSize != sizeof(m_headerSignature))
                    {
                        AZ_Warning("Archive", false, "ZD_ERROR_DATA_IS_CORRUPT: Bad signature header");
                        return false;
                    }
                }
            }
            else
            {
                // Unexpected technique
                AZ_Warning("Archive", false, "ZD_ERROR_DATA_IS_CORRUPT: Comment field is the wrong length");
                return false;
            }
        }


        // we don't support multivolume archives
        if (m_CDREnd.nDisk != 0
            || m_CDREnd.nCDRStartDisk != 0
            || m_CDREnd.numEntriesOnDisk != m_CDREnd.numEntriesTotal)
        {
            AZ_Warning("Archive", false, "ZD_ERROR_UNSUPPORTED: Multivolume archive detected.Current version of ZipDir does not support multivolume archives");
            return false;
        }

        // if the central directory offset or size are out of range,
        // the CDREnd record is probably corrupt
        if (m_CDREnd.lCDROffset > m_nCDREndPos
            || m_CDREnd.lCDRSize > m_nCDREndPos
            || m_CDREnd.lCDROffset + m_CDREnd.lCDRSize > m_nCDREndPos)
        {
            AZ_Warning("Archive", false, "ZD_ERROR_DATA_IS_CORRUPT: The central directory offset or size are out of range, the pak is probably corrupt, try to repare or delete the file");
            return false;
        }

        BuildFileEntryMap();

        return true;
    }