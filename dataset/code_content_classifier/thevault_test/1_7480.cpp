void FourierKnot::apply(Matrix3 &m) {
  // This rotation matrix has a trigo pos orientation!
  c0 = m*c0;
  for (uint i=0;i<csin.size();++i) {
    csin[i] = m*csin[i];
    ccos[i] = m*ccos[i];
  }
}