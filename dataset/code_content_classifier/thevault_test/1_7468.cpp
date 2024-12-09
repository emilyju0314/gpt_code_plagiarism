int Vector4::operator==(const Vector4 &v) const {
  if (_v[0]==v[0] && _v[1]==v[1] &&
      _v[2]==v[2] && _v[3]==v[3]) return 1;
  else return 0;
}