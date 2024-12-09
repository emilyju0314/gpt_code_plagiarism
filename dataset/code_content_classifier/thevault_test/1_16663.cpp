static bool Aac_f_master_Compute_0(int8u &num_env_bands_Master, int8u* f_Master, sbr_handler *sbr, int8u  k0, int8u  k2)
{
    int8u dk, numBands;
    if (sbr->bs_alter_scale)
    {
        dk=1;
        numBands=(((k2-k0+2)>>2)<<1);
    }
    else
    {
        dk=2;
        numBands=(((k2-k0)>>1)<<1);
    }

    int8u k2Achieved=k0+numBands*dk;
    int8s k2Diff=k2-k2Achieved;
    int8s vDk[64] = { 0 };
    for (int8u k=0; k<numBands; k++)
        vDk[k]=dk;

    if (k2Diff)
    {
        int8s  incr;
        int8u  k;
        if (k2Diff>0)
        {
            incr=-1;
            k=numBands-1;
        }
        else
        {
            incr=1;
            k=0;
        }

        while (k2Diff)
        {
            if (k >= 64)
                break;
            vDk[k]-=incr;
            k+=incr;
            k2Diff+=incr;
        }
    }

    f_Master[0]=k0;
    for (int8u k=1; k<=numBands; k++)
        f_Master[k]=f_Master[k-1]+vDk[k-1];

    num_env_bands_Master=numBands;

    return true;
}