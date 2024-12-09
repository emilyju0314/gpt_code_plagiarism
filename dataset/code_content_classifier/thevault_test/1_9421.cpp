void MyBytesFromGF2X(unsigned char* buffer, NTL::GF2X& p, int numbytes) {
    int degree = NTL::deg(p);
    memset(buffer,0,numbytes);
    for(int i=0; i<=degree; i++) {
        if(NTL::IsOne(NTL::coeff(p,i))) {
            buffer[i/8] |= 1 << i%8;
        }
    }
}