Matrix3::Matrix3(const FLOAT_TYPE &x00, const FLOAT_TYPE &x01, const FLOAT_TYPE &x02,
                 const FLOAT_TYPE &x10, const FLOAT_TYPE &x11, const FLOAT_TYPE &x12,
                 const FLOAT_TYPE &x20, const FLOAT_TYPE &x21, const FLOAT_TYPE &x22) {
  _v[0] = Vector3(x00,x10,x20);
  _v[1] = Vector3(x01,x11,x21);
  _v[2] = Vector3(x02,x12,x22);
}