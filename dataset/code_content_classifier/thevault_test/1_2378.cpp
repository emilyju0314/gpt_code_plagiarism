inline double linear_interpolate_3(double const x0, double const x1, double const y0,
                                   double const y1, double const z0, double const z1,
                                   double const f000, double const f100, double const f001,
                                   double const f101, double const f010, double const f110,
                                   double const f011, double const f111, double const x,
                                   double const y, double const z) {
  Require(std::abs(x1 - x0) > std::numeric_limits<double>::epsilon());
  Require(std::abs(y1 - y0) > std::numeric_limits<double>::epsilon());
  Require(std::abs(z1 - z0) > std::numeric_limits<double>::epsilon());
  Require(x >= x0);
  Require(x <= x1);
  Require(y >= y0);
  Require(y <= y1);
  Require(z >= z0);
  Require(z <= z1);

  const double xd = (x - x0) / (x1 - x0);
  const double yd = (y - y0) / (y1 - y0);
  const double zd = (z - z0) / (z1 - z0);

  const double f00 = f000 * (1. - xd) + f100 * xd;
  const double f01 = f001 * (1. - xd) + f101 * xd;
  const double f10 = f010 * (1. - xd) + f110 * xd;
  const double f11 = f011 * (1. - xd) + f111 * xd;

  const double f0 = f00 * (1. - yd) + f10 * yd;
  const double f1 = f01 * (1. - yd) + f11 * yd;

  const double f = f0 * (1. - zd) + f1 * zd;

  return f;
}