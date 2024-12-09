inline bool typeFromString(const std::string& s, Type* t)
{
    bool ok = true;
    if (s == "int8")
        *t = int8;
    else if (s == "uint8")
        *t = uint8;
    else if (s == "int16")
        *t = int16;
    else if (s == "uint16")
        *t = uint16;
    else if (s == "int32")
        *t = int32;
    else if (s == "uint32")
        *t = uint32;
    else if (s == "int64")
        *t = int64;
    else if (s == "uint64")
        *t = uint64;
    else if (s == "float32")
        *t = float32;
    else if (s == "float64")
        *t = float64;
    else
        ok = false;
    return ok;
}