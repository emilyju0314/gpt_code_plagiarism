QSPLINE::QSPLINE( // constructor
    const QSPLINE &src) {
  segments = 0;
  xcoords = nullptr;
  quadratics = nullptr;
  *this = src;
}