inline size_t how_many_bytes_to_fill(_TDH_IN_TYPE type)
    {
        static_assert(sizeof(float) == 4, "sizeof(float) must be 4, defined on MSDN");

        switch (type) {
        case TDH_INTYPE_NULL:          throw std::runtime_error("supposed to be unusued -- something horrible is happening");
        case TDH_INTYPE_UNICODESTRING: return sizeof(wchar_t);
        case TDH_INTYPE_ANSISTRING:    return sizeof(char);
        case TDH_INTYPE_INT8:          return sizeof(int8_t);
        case TDH_INTYPE_UINT8:         return sizeof(uint8_t);
        case TDH_INTYPE_INT16:         return sizeof(int16_t);
        case TDH_INTYPE_UINT16:        return sizeof(uint16_t);
        case TDH_INTYPE_INT32:         return sizeof(int32_t);
        case TDH_INTYPE_UINT32:        return sizeof(uint32_t);
        case TDH_INTYPE_INT64:         return sizeof(int64_t);
        case TDH_INTYPE_UINT64:        return sizeof(int64_t);
        case TDH_INTYPE_FLOAT:         return sizeof(float);
        case TDH_INTYPE_DOUBLE:        return sizeof(double);
        case TDH_INTYPE_BOOLEAN:       return sizeof(uint32_t); // 4-byte bool, defined on MSDN
        case TDH_INTYPE_BINARY:        return sizeof(char);
        case TDH_INTYPE_GUID:          return sizeof(GUID);
        case TDH_INTYPE_POINTER:       return sizeof(char*);
        case TDH_INTYPE_FILETIME:      return sizeof(FILETIME);
        case TDH_INTYPE_SYSTEMTIME:    return sizeof(SYSTEMTIME);
        case TDH_INTYPE_SID:           return sizeof(PSID);
        case TDH_INTYPE_HEXINT32:      return sizeof(uint32_t);
        case TDH_INTYPE_HEXINT64:      return sizeof(uint64_t);
        default: break;
        };

        throw std::runtime_error("Unexpected fill type");
    }