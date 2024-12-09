void FourierKnot::flip_dir(float sh) {
  if (sh!=0)
    this->shift(sh);
  for (Coeffs::iterator i=csin.begin();i!=csin.end();++i)
    *i = -(*i);
  if (sh!=0)
    this->shift(-sh);
}