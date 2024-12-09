void FourierKnot::toCurveOnS3(const int sampling, Curve<Vector4> *curve) {
  float isampling = 1./(float)sampling, s;
  Vector4 p,t;
  for (int i=0;i<sampling;++i) {
    s = (float)i*isampling;
    // Tangent gets normalized in biarc constructor
    project_to_S3((*this)(s), this->prime(s), p, t);
    curve->append(p,t);
  }
}