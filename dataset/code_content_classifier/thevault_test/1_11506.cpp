std::tm CZIP::convertModificationDateTime(std::uint16_t dateWord, std::uint16_t timeWord)
    {
        std::time_t rawtime = 0;
        std::tm modificationDateTime;
        std::time(&rawtime);
        std::memcpy(&modificationDateTime, std::localtime(&rawtime), sizeof(std::tm));
        modificationDateTime.tm_sec = (timeWord & 0b11111) >> 2;
        modificationDateTime.tm_min = (timeWord & 0b11111100000) >> 5;
        modificationDateTime.tm_hour = (timeWord & 0b1111100000000000) >> 11;
        modificationDateTime.tm_mday = (dateWord & 0b11111);
        modificationDateTime.tm_mon = ((dateWord & 0b111100000) >> 5) - 1;
        modificationDateTime.tm_year = ((dateWord & 0b1111111000000000) >> 9) + 80;
        mktime(&modificationDateTime);
        return (modificationDateTime);
    }