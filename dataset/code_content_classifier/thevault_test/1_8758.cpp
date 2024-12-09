RealType estimate
    (
    int elen,
    RealType *e
    )
{
    RealType Q;
    int eindex;

    Q = e[0];
    for (eindex = 1; eindex < elen; eindex++) {
        Q += e[eindex];
    }
    return Q;
}