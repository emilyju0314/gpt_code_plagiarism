void FourierKnot::rotate(const Vector3 v,float alpha) {
  // This rotation matrix has a trigo pos orientation!
  Matrix3 D; D.rotAround(v,alpha);
  c0 = D*c0;
  for (uint i=0;i<csin.size();++i) {
    csin[i] = D*csin[i];
    ccos[i] = D*ccos[i];
  }
}