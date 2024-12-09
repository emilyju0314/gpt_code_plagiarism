bool Importer::CheckIfIsValidNodeMapFile(MCore::File* f, MCore::Endian::EEndianType* outEndianType) const
    {
        MCORE_ASSERT(f->GetIsOpen());

        // verify if we actually are dealing with a valid actor file
        FileFormat::NodeMap_Header  header;
        if (f->Read(&header, sizeof(FileFormat::NodeMap_Header)) == 0)
        {
            MCore::LogError("Failed to read the node map file header!");
            return false;
        }

        // check the FOURCC
        if (header.m_fourCc[0] != 'N' || header.m_fourCc[1] != 'O' || header.m_fourCc[2] != 'M' || header.m_fourCc[3] != 'P')
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

        // yes, it is a valid node map file!
        return true;
    }