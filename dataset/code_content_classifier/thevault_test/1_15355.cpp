inline size_t hashMe(char* me, size_t len) {
/*    size_t code = 0;
#ifndef HASH_FOR_TPCH
    for (int i = 0; i < len; i += 8) {

        int low = 0;
        int high = 0;

        for (int j = 0; j < 4; j++) {
            if (i + j < len) {
                low += (me[i + j] & 0xFF) << (8 * j);
            } else {
                low += 123 << (8 * j);
            }
        }

        if (len <= 4)
            high = low;
        else {
            for (int j = 4; j < 8; j++) {
                if (i + j < len) {
                    high += (me[i + j] & 0xFF) << (8 * (j - 3));
                } else {
                    high += 97 << (8 * (j - 3));
                }
            }
        }

        size_t returnVal = ((size_t)newHash(high)) << 32;
        returnVal += newHash(low) & 0xFFFFFFFF;
        code = code ^ returnVal;
    }
#else
    for (int i = 0; i < len; i++) {
        code = 31 * code + me[len-1-i];
    }
#endif*/
    //std::cout << me << ":" << code << std::endl;
    return std::hash<std::string>{}(std::string(me));
}