int Matrix3::operator==(const Matrix3 &m) const {
  if ((_v[0]==m[0])&(_v[1]==m[1])&(_v[2]==m[2])) return 1;
  else
    return 0;
}