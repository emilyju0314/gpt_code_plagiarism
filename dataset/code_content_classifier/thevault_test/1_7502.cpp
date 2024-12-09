FLOAT_TYPE Matrix3::det() {
  return
    (*this)[0][0] * (*this)[1][1] * (*this)[2][2]
    + (*this)[1][0] * (*this)[2][1] * (*this)[0][2]
    + (*this)[2][0] * (*this)[0][1] * (*this)[1][2]
    - (*this)[0][2] * (*this)[1][1] * (*this)[2][0]
    - (*this)[1][2] * (*this)[2][1] * (*this)[0][0]
    - (*this)[2][2] * (*this)[0][1] * (*this)[1][0];
}