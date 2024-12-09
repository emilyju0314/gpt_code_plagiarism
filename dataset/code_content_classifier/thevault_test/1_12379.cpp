bool Importer::CheckIfIsValidMotionFile(MCore::File* f, MCore::Endian::EEndianType* outEndianType) const
    {
        MCORE_ASSERT(f->GetIsOpen());

        // verify if we actually are dealing with a valid actor file
        FileFormat::Motion_Header  header;
        if (f->Read(&header, sizeof(FileFormat::Motion_Header)) == 0)
        {
            MCore::LogError("Failed to read the motion file header!");
            return false;
        }

        // check the FOURCC
        if ((header.m_fourcc[0] != 'M' || header.m_fourcc[1] != 'O' || header.m_fourcc[2] != 'T' || header.m_fourcc[3] != ' '))
        {
            return false;
        }

        // read the chunks
        switch (header.m_endianType)
        {
        case 0:
            *outEndianType  = MCore::Endian::ENDIAN_LITTLE;
            break;
        case 1:
            *outEndianType  = MCore::Endian::ENDIAN_BIG;
            break;
        default:
            MCore::LogError("Unsupported endian type used! (endian type = %d)", header.m_endianType);
            return false;
        }

        // yes, it is a valid motion file!
        return true;
    }