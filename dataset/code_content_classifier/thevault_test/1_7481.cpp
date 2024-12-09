void FourierKnot::mirror(const Vector3 v) {
  Vector3 v2 = v/v.norm();
  c0 = c0 -2*v2.dot(c0)*v2;
  for (uint i=0;i<csin.size();++i) {
    csin[i] = csin[i]- 2*v2.dot(csin[i])*v2;
    ccos[i] = ccos[i]- 2*v2.dot(ccos[i])*v2;
  }
}