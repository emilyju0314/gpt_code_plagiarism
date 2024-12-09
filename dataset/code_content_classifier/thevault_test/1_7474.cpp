FourierKnot FourierKnot::operator*(const float d) const {
  FourierKnot fk;
  for (uint i=0;i<csin.size();++i) {
    fk.csin.push_back(csin[i]*d);
    fk.ccos.push_back(ccos[i]*d);
  }
  fk.c0 = c0*d;
  return fk;
}