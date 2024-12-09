ColumnVector DSCFwdModelBase::ApplyDispersion(const ColumnVector &aif, double disp_s, double disp_p) const
{
    unsigned int nt = aif.Nrows();
    ColumnVector vtf(nt);

    double s = exp(disp_s); // FIXME required or use param transforms?
    double p = exp(disp_p);
    for (unsigned int i = 1; i <= nt; i++)
    {
        double t = (i - 1) * m_delt;
        vtf(i) = pow(s, 1 + s * p) * pow(t, s * p) * exp(-s * t) / true_gamma(1 + s * p);
    }

    return DoConvolution(vtf, aif);
}