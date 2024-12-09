int128_t int128_t::DivideDouble(int128_t *A,const int128_t &B)
{
    int128 quotient=*A;
    int128 remainder;//==0

    if ((int128_t)(B)==0) //TODO: fix this const mess
    {
        throw "division by zero";
    }
    
    for (int x=0;x<A->size;x++)
    {
        int hibit=shiftleft(&quotient,0);
        shiftleft(&remainder,hibit);
        if (remainder>=B)
        {
            SubDouble(&remainder,B,0); //remainder-=*B;
            quotient.Lo|=1; //quotient|=1;
        }
    }

    *A=quotient;
    return remainder;
}