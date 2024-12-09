int CSMTP::decodeChar(char ch)
    {
        auto basePtr = kCB64;
        while (*basePtr)
        {
            if (ch == *basePtr)
                return (basePtr - kCB64);
            basePtr++;
        }
        return (0);
    }