Long spqr_cumsum
(
    // input, not modified
    Long n,

    // input/output
    Long *X                         // size n+1. X = cumsum ([0 X])
)
{
    Long itot, t, x, k ;

    // -------------------------------------------------------------------------
    // X = cumsum ([0 X])
    // -------------------------------------------------------------------------

    itot = 0 ;
    if (X != NULL)
    {
        for (k = 0 ; k < n ; k++)
        {
            t = itot ;              // t = sum (X [0:k-1])
            x = X [k] ;
            itot += x ;
            X [k] = t ;
        }
        X [n] = itot ;
    }

    return (itot) ;
}