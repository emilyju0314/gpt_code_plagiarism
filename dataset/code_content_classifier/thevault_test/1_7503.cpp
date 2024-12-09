Matrix3 Matrix3::operator*(const Matrix3 &m) {
  Matrix3 tmp;
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      for (int k=0;k<3;k++)
	tmp[j][i]+=(_v[k][i]*m[j][k]);
    }
  }
  return tmp;
}