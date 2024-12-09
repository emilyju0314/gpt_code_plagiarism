std::string tld_encode(const std::string& tld, int& level)
{
    std::string result;
    level = 0;

    int max(tld.length());
    const char *p = tld.data();
    for(int l = 0; l < max; ++l)
    {
        char c(p[l]);
        if(static_cast<unsigned char>(c) < 0x20)
        {
            fprintf(stderr, "error: controls characters (^%c) are not allowed in TLDs (%s).\n", c, p);
            exit(1);
        }
        if((c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9')
        || c == '.' || c == '-')
        {
            // these are accepted as is; note that we already checked the
            // validty of the data w
            if(c == '.')
            {
                ++level;
            }
            result += c;
        }
        else
        {
            // add/remove as appropriate
            //
            if(c == '/' || c == ':' || c == '&')
            {
                fprintf(stderr, "error: character (^%c) is not allowed in TLDs.\n", c);
                exit(1);
            }
            result += '%';
            int byte(c & 255);
            if(byte < 16)
            {
                result += '0';
                result += to_hex(byte);
            }
            else
            {
                result += to_hex(byte >> 4);
                result += to_hex(byte & 15);
            }
        }
    }
    // at this time the maximum level we declared is 4 but there are cases
    // where countries defined 5 levels (which is definitively crazy!)
    // there is also one Amazon server using 6 levels
    if(level < 0 || level > 6)
    {
        fprintf(stderr, "error: level out of range (%d) in \"%s\"; if larger than the maximum limit, you may want to increase the limit.\n", level, p);
        exit(1);
    }

    return result;
}