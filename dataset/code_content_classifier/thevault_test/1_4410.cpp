inline double vtkColorTransferFunctionAngleDiff(double a1, double a2)
{
  double adiff = a1 - a2;
  if (adiff < 0.0) adiff = -adiff;
  while (adiff >= 2*vtkMath::DoublePi()) adiff -= 2*vtkMath::DoublePi();
  if (adiff > vtkMath::DoublePi()) adiff = 2*vtkMath::DoublePi() - adiff;
  return adiff;
}