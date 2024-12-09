void CosineBinner2D::fill(double costheta, double costheta2, double phi, double value)
{
    if( costheta<=s_cosmin || costheta2<s_cosmin2) return;
    (*this)(costheta,costheta2) += value;
    // get the phi index and index into the array
    (*this)(costheta,costheta2,phi) += value;
}