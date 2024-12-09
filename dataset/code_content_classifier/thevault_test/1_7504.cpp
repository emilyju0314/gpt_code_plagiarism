Vector3 Matrix3::operator*(const Vector3 &v) {
  FLOAT_TYPE a[3];
  for (int i=0;i<3;i++) {
    a[i] = 0;
    for (int j=0;j<3;j++) {
      a[i] += (v[j]*_v[j][i]);
    }
  }
  return Vector3(a[0],a[1],a[2]);
}