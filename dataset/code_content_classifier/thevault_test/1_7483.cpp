void FourierKnot::shift(float sh) {
  Coeffs tmpsin(csin), tmpcos(ccos);
  float f,vcos,vsin;
  for (uint i=0;i<csin.size();++i) {
    f = (float)(i+1)*(2.0*M_PI);
    vcos = cos(f*sh); vsin = sin(f*sh);
    ccos[i] =  vcos*tmpcos[i] + vsin*tmpsin[i];
    csin[i] = -vsin*tmpcos[i] + vcos*tmpsin[i];
  }
}