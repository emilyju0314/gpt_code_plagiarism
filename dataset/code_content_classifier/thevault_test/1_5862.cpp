char toHex(unsigned char v)
{
    if (v <= 9)
    {
        return '0' + v;
    }
    return 'A' + v - 10;
}