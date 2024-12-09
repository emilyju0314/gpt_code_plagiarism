void vtkCamera::SetViewShear(double dxdz, double dydz, double center)
{
  if(dxdz   != this->ViewShear[0] ||
     dydz   != this->ViewShear[1] ||
     center != this->ViewShear[2])
    {
    this->Modified();
    this->ViewingRaysModified();

    this->ViewShear[0] = dxdz;
    this->ViewShear[1] = dydz;
    this->ViewShear[2] = center;

    this->ComputeViewPlaneNormal();
    }
}