void FourierKnot::toCurve(float(*pt2func)(float), const int sampling,
                          Curve<Vector3> *curve) {
  float isampling = 1./(float)sampling, s;
  for (int i=0;i<sampling;++i) {
    s = pt2func((float)i*isampling);
    // Tangent gets normalized in biarc constructor
    curve->append((*this)(s),this->prime(s));
  }
}