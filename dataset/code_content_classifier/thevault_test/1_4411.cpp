inline double vtkColorTransferFunctionAdjustHue(const double msh[3],
                                                double unsatM)
{
  if (msh[0] >= unsatM - 0.1)
    {
    // The best we can do is hold hue constant.
    return msh[2];
    }
  else
    {
    // This equation is designed to make the perceptual change of the
    // interpolation to be close to constant.
    double hueSpin = (  msh[1]*sqrt(unsatM*unsatM - msh[0]*msh[0])
                      / (msh[0]*sin(msh[1])) );
    // Spin hue away from 0 except in purple hues.
    if (msh[2] > -0.3*vtkMath::DoublePi())
      {
      return msh[2] + hueSpin;
      }
    else
      {
      return msh[2] - hueSpin;
      }
    }
}