bool Dsettings :: is_powerOf2(unsigned num)
{
    int bits = myLog2(num);
    return ((unsigned)(0x1 << bits) == num);
}