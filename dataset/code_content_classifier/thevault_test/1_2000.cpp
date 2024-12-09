unsigned int BankChecker::
getLtid( unsigned int tidx, unsigned int tidy, unsigned int tidz,
         unsigned int bdimx, unsigned int bdimy, unsigned int /*bdimz*/ ) 
{
    return tidx + (tidy * bdimx) + tidz * (bdimx * bdimy);
}