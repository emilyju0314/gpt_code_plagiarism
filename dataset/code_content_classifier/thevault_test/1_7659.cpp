void fresnelApprox( double xxa, double *ssa, double *cca )
{
    double f, g, cc, ss, c, s, t, u;
    double x, x2;

    x = fabs(xxa);
    x2 = x * x;
    if( x2 < 2.5625 )
    {
        t = x2 * x2;
        ss = x * x2 * polevl( t, dssn);
        cc = x * polevl( t, dscn);
        goto done;
    }

    if( x > 36974.0 )
    {
        cc = 0.5;
        ss = 0.5;
        goto done;
    }

    /*        Asymptotic power series auxiliary functions
    *        for large argument
    */
    x2 = x * x;
    t = PI * x2;
    u = 1.0/(t * t);
    t = 1.0/t;
    f = 1.0 - u * polevl( u, dsfn);
    g = t * polevl( u, dsgn);

    t = HALFPI * x2;
    c = cos(t);
    s = sin(t);
    t = PI * x;
    cc = 0.5  +  (f * s  -  g * c)/t;
    ss = 0.5  -  (f * c  +  g * s)/t;

done:
    if( xxa < 0.0 )
    {
        cc = -cc;
        ss = -ss;
    }

    *cca = cc;
    *ssa = ss;
}