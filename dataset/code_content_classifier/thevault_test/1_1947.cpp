void
computeGold(char* reference, char* idata, const unsigned int len)
{
    for(unsigned int i = 0; i < len; ++i)
        reference[i] = idata[i] - 10;
}