void FourierKnot::toCurve(const int sampling, Curve<Vector3> *curve) {
  float isampling = 1./(float)sampling, s;
  for (int i=0;i<sampling;++i) {
    s = (float)i*isampling;
    // Tangent gets normalized in biarc constructor
    curve->append((*this)(s),this->prime(s));
  }
}