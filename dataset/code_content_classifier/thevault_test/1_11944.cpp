bool NodeMap::WriteFileString(MCore::DiskFile* f, const AZStd::string& textToSave, MCore::Endian::EEndianType targetEndianType) const
    {
        MCORE_ASSERT(f);

        // convert endian and write the number of characters that follow
        if (textToSave.empty())
        {
            uint32 numCharacters = 0;
            MCore::Endian::ConvertUnsignedInt32To(&numCharacters, targetEndianType);
            if (f->Write(&numCharacters, sizeof(uint32)) == 0)
            {
                return false;
            }

            return true;
        }
        else
        {
            uint32 numCharacters = static_cast<uint32>(textToSave.size());
            MCore::Endian::ConvertUnsignedInt32To(&numCharacters, targetEndianType);
            if (f->Write(&numCharacters, sizeof(uint32)) == 0)
            {
                return false;
            }
        }

        // write the string in UTF8 format
        if (f->Write(textToSave.c_str(), textToSave.size()) == 0)
        {
            return false;
        }

        return true;
    }