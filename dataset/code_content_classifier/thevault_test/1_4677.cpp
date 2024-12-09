inline GUID guid_parser::parse_guid(const char* str, unsigned int length)
    {
        if (length != UUID_STRING_LENGTH)
        {
            std::stringstream message;
            message << "Input data has incorrect length. Expected "
                << UUID_STRING_LENGTH
                << ", got "
                << length;
            throw std::runtime_error(message.str());
        }

        GUID guid = { 0 };

        // Check that hyphens are in expected places as a formatting issue.
        if (str[STR_POSITION_DATA2 - 1] != DELIMITER ||
            str[STR_POSITION_DATA3 - 1] != DELIMITER ||
            str[STR_POSITION_DATA4_PART1 - 1] != DELIMITER ||
            str[STR_POSITION_DATA4_PART2 - 1] != DELIMITER)
        {
            throw std::runtime_error("Missing a hyphen where one was expected.");
        }

        // Use from_hex_string for Data1, Data2, and Data3 because of endianness of the data
        // Use hex_string_to_bytes for Data4's array elements because it's byte by byte instead
        auto success = guid_parser::hex_string_to_number(str + STR_POSITION_DATA1, guid.Data1)
            && guid_parser::hex_string_to_number(str + STR_POSITION_DATA2, guid.Data2)
            && guid_parser::hex_string_to_number(str + STR_POSITION_DATA3, guid.Data3)
            && guid_parser::hex_string_to_bytes(str + STR_POSITION_DATA4_PART1, reinterpret_cast<unsigned char*>(&guid.Data4[0]), 2)
            && guid_parser::hex_string_to_bytes(str + STR_POSITION_DATA4_PART2, reinterpret_cast<unsigned char*>(&guid.Data4[2]), 6);

        if (!success)
        {
            throw std::runtime_error("GUID string contains non-hex digits where hex digits are expected.");
        }

        return guid;
    }