int* vtkViewport::GetSize()
{
  if (this->VTKWindow)
  {
    int lowerLeft[2];
    double* vport = this->GetViewport();

    double vpu, vpv;
    vpu = vport[0];
    vpv = vport[1];
    this->NormalizedDisplayToDisplay(vpu, vpv);
    lowerLeft[0] = static_cast<int>(vpu + 0.5);
    lowerLeft[1] = static_cast<int>(vpv + 0.5);
    double vpu2, vpv2;
    vpu2 = vport[2];
    vpv2 = vport[3];
    this->NormalizedDisplayToDisplay(vpu2, vpv2);
    this->Size[0] = static_cast<int>(vpu2 + 0.5) - lowerLeft[0];
    this->Size[1] = static_cast<int>(vpv2 + 0.5) - lowerLeft[1];
  }
  else
  {
    this->Size[0] = this->Size[1] = 0;
  }

  return this->Size;
}