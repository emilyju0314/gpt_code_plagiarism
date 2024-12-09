void fresnelLow( const Packet4f &xxa, Packet4f *ssa, Packet4f *cca )
{
    Packet4f cc, ss, t;
    Packet4f x, x2;

    x = pabs(xxa);
    x2 = pmul(x, x);

    t = pmul(x2, x2);
    ss = pmul(x, pmul(x2, vecpolevl( t, ssn)));
    cc = pmul(x, vecpolevl( t, scn));

    *ssa = packetTransferSign(ss, xxa);
    *cca = packetTransferSign(cc, xxa);
}