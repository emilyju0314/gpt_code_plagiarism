void ftostr53s(float x, char c[8]) {
    char conv[10] = { 0 };
    long xx=x*1000;
    if (xx >= 0)
        conv[0]=(xx/10000000)%10+'0';
    else
        conv[0]='-';
    xx = abs(xx);
    conv[1]=(xx/1000000)%10+'0';
    conv[2]=(xx/100000)%10+'0';
    conv[3]=(xx/10000)%10+'0';
    conv[4]=(xx/1000)%10+'0';
    conv[5] = '.';
    conv[6] = (xx / 100) % 10 + '0';
    conv[7] = (xx / 10) % 10 + '0';
    conv[8] = (xx) % 10 + '0';
    conv[9] = 0;
    strncpy(c, conv, 10);
}