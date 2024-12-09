void RGB_Move(unsigned char * dat, int u, int len){
        for(int i = 0; i<len; i+=3) dat[i] = 255 * std::sin((i/25.0f)*((2/3.0f)* PI) + u / 10.0f);
        for(int i = 1; i<len; i+=3) dat[i] = 255 * std::sin((i/25.0f)*((2/3.0f)* PI) + ((2/3.0f)*PI) + u / 10.0f);
        for(int i = 2; i<len; i+=3) dat[i] = 255 * std::sin((i/25.0f)*((2/3.0f)* PI) + (2*(2/3.0f)*PI) + u / 10.0f);
    }