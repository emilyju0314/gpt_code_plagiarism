void RGB_Color_Pulse(unsigned char * dat, int R, int G, int B, int u, int len){
        for(int i = 0; i < len; i++){
            if((i%3) == 0) dat[i] = R * std::abs(std::sin((u/53.0f) * PI));
            if((i%3) == 1) dat[i] = G * std::abs(std::sin((u/53.0f) * PI));
            if((i%3) == 2) dat[i] = B * std::abs(std::sin((u/53.0f) * PI));
        }
    }