void FourierKnot::mul(const float d) {
  for (uint i=0;i<csin.size();++i) {
    csin[i]*=d;
    csin[i]*=d;
  }
  c0*=d;
}