unsigned
ML_RandomLessThanN(unsigned nModulus)
{
    unsigned nRemainder, n;

    nRemainder = 0xFFFFFFFF % nModulus;
    do {
        n = ML_RandomUnsigned();
    } while (n <= nRemainder);
    return n % nModulus;
}