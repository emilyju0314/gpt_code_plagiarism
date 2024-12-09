void CZIPIO::getZip64ExtendedInfoExtraField(Zip64ExtendedInfoExtraField &zip64ExtendedInfo, std::vector<std::uint8_t> &info)
    {
        std::uint16_t signature = 0;
        std::uint16_t fieldSize = 0;
        std::uint16_t fieldCount = 0;
        std::uint8_t *buffptr = &info[0];
        while (fieldCount < info.size())
        {
            buffptr = getField(signature, buffptr);
            buffptr = getField(fieldSize, buffptr);
            if (signature == zip64ExtendedInfo.signature)
            {
                if (fieldOverflow(static_cast<std::uint32_t>(zip64ExtendedInfo.originalSize)))
                {
                    buffptr = getField(zip64ExtendedInfo.originalSize, buffptr);
                    fieldSize -= sizeof(std::uint64_t);
                    if (!fieldSize)
                        break;
                }
                if (fieldOverflow(static_cast<std::uint32_t>(zip64ExtendedInfo.compressedSize)))
                {
                    buffptr = getField(zip64ExtendedInfo.compressedSize, buffptr);
                    fieldSize -= sizeof(std::uint64_t);
                    if (!fieldSize)
                        break;
                }
                if (fieldOverflow(static_cast<std::uint32_t>(zip64ExtendedInfo.fileHeaderOffset)))
                {
                    buffptr = getField(zip64ExtendedInfo.fileHeaderOffset, buffptr);
                    fieldSize -= sizeof(std::uint64_t);
                    if (!fieldSize)
                        break;
                }
                buffptr = getField(zip64ExtendedInfo.diskNo, buffptr);
                break;
            }
            fieldCount += (fieldSize + (sizeof(std::uint16_t) * 2));
            buffptr += fieldSize;
        }
    }