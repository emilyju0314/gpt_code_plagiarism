double Integrand(double x1, double y1, double x2, double y2)
{
  return 4*x1*x1;  //  (H_1(x)*H_1(x), h_1(x) = 2x, the other polynomials are H_0(x) = 1
  //   final result   2 * sqrt(pi)^4  = 2 * pi^2
  //  if  (2.0*(x1-x2)*(x1-x2)+2.0*(y1-y2)*(y1-y2) != 0.0)
  //  return 4.0/(sqrt(2.0*(x1-x2)*(x1-x2)+2.0*(y1-y2)*(y1-y2)));
  //else
  //  return 0.0;
}