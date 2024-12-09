inline const char* typeToString(Type t)
{
    const char* p = nullptr;
    switch (t) {
    case int8:
        p = "int8";
        break;
    case uint8:
        p = "uint8";
        break;
    case int16:
        p = "int16";
        break;
    case uint16:
        p = "uint16";
        break;
    case int32:
        p = "int32";
        break;
    case uint32:
        p = "uint32";
        break;
    case int64:
        p = "int64";
        break;
    case uint64:
        p = "uint64";
        break;
    case float32:
        p = "float32";
        break;
    case float64:
        p = "float64";
        break;
    }
    return p;
}