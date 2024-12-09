void CosineBinner2D::fill(double costheta, double costheta2, double value)
{
    if( costheta<=s_cosmin || costheta2<s_cosmin2) return;
    (*this)(costheta,costheta2) += value;
}