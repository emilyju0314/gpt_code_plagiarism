double Ei(double const x) {
  // Check(x) // x can be any real value.

  using std::numeric_limits;
  const size_t MAXIT = 100;
  const double EULER = 0.57721564901533;
  const double EPS = numeric_limits<double>::epsilon();
  const double FPMIN = numeric_limits<double>::min() / EPS;

  double fact, prev, sum, term;

  if (x <= 0.0) {
    return -1 * En(1, fabs(x));
  }

  if (x < FPMIN)
    return log(x) + EULER; //Avoid failure from underflow

  if (x <= -log(EPS)) //use power series
  {
    sum = 0.0;
    fact = 1.0;
    size_t k(1);
    for (; k <= MAXIT; ++k) {
      fact *= x / static_cast<double>(k);
      term = fact / static_cast<double>(k);
      sum += term;
      if (term < EPS * sum)
        break;
    }
    Insist(k <= MAXIT, "Series failed in Ei");
    return sum + log(x) + EULER;
  } else //Use asymptotic expansion
  {
    sum = 0.0;
    term = 1.0; //starts with second term
    for (size_t k = 1; k <= MAXIT; ++k) {
      prev = term;
      term *= static_cast<double>(k) / x;
      if (term < EPS)
        break; //term approximates relative error

      if (term < prev) {
        sum += term; //still converging
      } else {
        sum -= prev;
        break; //diverging, take off last term
      }
    }
    return exp(x) * (1.0 + sum) / x;
  }
}