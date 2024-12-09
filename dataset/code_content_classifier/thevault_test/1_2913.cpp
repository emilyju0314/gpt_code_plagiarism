UINT32 RTObject::jvmHashCode(const char* name) {
    const char *str = name;
    UINT32 hash = 0;

    while (*str != '\0') {
        hash = (hash * 31) + *str;
        // hash = (hash << 5) - hash + *str;
        str++;
    }

    // FORCE hash code is positive
    hash = hash & 0x7FFFFFFF;

    return hash;
}