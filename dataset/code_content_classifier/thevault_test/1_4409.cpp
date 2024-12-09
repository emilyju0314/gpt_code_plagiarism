inline void vtkColorTransferFunctionLabToMsh(const double lab[3], double msh[3])
{
  const double &L = lab[0];
  const double &a = lab[1];
  const double &b = lab[2];
  double &M = msh[0];
  double &s = msh[1];
  double &h = msh[2];

  M = sqrt(L*L + a*a + b*b);
  s = (M > 0.001) ? acos(L/M) : 0.0;
  h = (s > 0.001) ? atan2(b,a) : 0.0;
}