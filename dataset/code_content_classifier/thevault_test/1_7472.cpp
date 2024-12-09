inline Vector3 on_torus(float u, float v, float tilt, float xoffset) {
  Vector3 vec((1+cos(v))*cos(u), (1+cos(v))*sin(u), sin(v));
  Matrix3 mat;
  mat.rotAround(Vector3(1,0,0), tilt);
  return (mat*vec+Vector3(xoffset,0,0));
}