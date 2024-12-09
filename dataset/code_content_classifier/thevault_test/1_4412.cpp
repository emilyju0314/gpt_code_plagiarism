inline void vtkColorTransferFunctionInterpolateDiverging(double s,
                                                         const double rgb1[3],
                                                         const double rgb2[3],
                                                         double result[3])
{
  double lab1[3], lab2[3];
  vtkMath::RGBToLab(rgb1, lab1);
  vtkMath::RGBToLab(rgb2, lab2);

  double msh1[3], msh2[3];
  vtkColorTransferFunctionLabToMsh(lab1, msh1);
  vtkColorTransferFunctionLabToMsh(lab2, msh2);

  // If the endpoints are distinct saturated colors, then place white in between
  // them.
  if (   (msh1[1] > 0.05) && (msh2[1] > 0.05)
      && (vtkColorTransferFunctionAngleDiff(msh1[2], msh2[2]) > 0.33*vtkMath::DoublePi()) )
    {
    // Insert the white midpoint by setting one end to white and adjusting the
    // scalar value.
    double Mmid = MY_MAX(msh1[0], msh2[0]);
    Mmid = MY_MAX(88.0, Mmid);
    if (s < 0.5)
      {
      msh2[0] = Mmid;  msh2[1] = 0.0;  msh2[2] = 0.0;
      s = 2.0*s;
      }
    else
      {
      msh1[0] = Mmid;  msh1[1] = 0.0;  msh1[2] = 0.0;
      s = 2.0*s - 1.0;
      }
    }

  // If one color has no saturation, then its hue value is invalid.  In this
  // case, we want to set it to something logical so that the interpolation of
  // hue makes sense.
  if ((msh1[1] < 0.05) && (msh2[1] > 0.05))
    {
    msh1[2] = vtkColorTransferFunctionAdjustHue(msh2, msh1[0]);
    }
  else if ((msh2[1] < 0.05) && (msh1[1] > 0.05))
    {
    msh2[2] = vtkColorTransferFunctionAdjustHue(msh1, msh2[0]);
    }

  double mshTmp[3];
  mshTmp[0] = (1-s)*msh1[0] + s*msh2[0];
  mshTmp[1] = (1-s)*msh1[1] + s*msh2[1];
  mshTmp[2] = (1-s)*msh1[2] + s*msh2[2];

  // Now convert back to RGB
  double labTmp[3];
  vtkColorTransferFunctionMshToLab(mshTmp, labTmp);
  vtkMath::LabToRGB(labTmp, result);
}