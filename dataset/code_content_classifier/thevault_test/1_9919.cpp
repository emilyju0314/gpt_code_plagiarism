void ftostr33s(float x, char c[8]) {
    char conv[8] = { 0 };
    long xx=x*1000;
    if (xx >= 0)
        conv[0]=(xx/100000)%10+'0';
    else
        conv[0]='-';
    xx = abs(xx);
    conv[1]=(xx/10000)%10+'0';
    conv[2]=(xx/1000)%10+'0';
    conv[3] = '.';
    conv[4] = (xx / 100) % 10 + '0';
    conv[5] = (xx / 10) % 10 + '0';
    conv[6] = (xx) % 10 + '0';
    conv[7] = 0;
    strncpy(c, conv, 8);
  }