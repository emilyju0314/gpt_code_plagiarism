bool tryParseConstant(string const & s, double & result, bool & outOfRange) {
    errno = 0;

    const char* cstr = s.c_str();
    char* endPtr;
    result = strtod(cstr, &endPtr);//todo: switch to from_chars when our compiler has compliant implementation

    ulong endIndex = endPtr - cstr;

    if (endIndex == s.length()) {
        return true;
    } else if (errno == ERANGE) {
        /*
         * todo:
         * i don't think gcc sets this or signals out of range in any way,
         * it just picks the closest aproximation, if this is okay which i think it is,
         * then we should probably just get rid of all this out of range stuff and
         * force it into range for compilers that don't do this for us.
         */
        outOfRange = true;
        return false;
    } else {
        outOfRange = false;
        return false;
    }

}