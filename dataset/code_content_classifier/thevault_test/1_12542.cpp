void vtkViewport::ViewToDisplay()
{
  if (this->VTKWindow)
  {
    double x = this->ViewPoint[0];
    double y = this->ViewPoint[1];
    double z = this->ViewPoint[2];
    this->ViewToDisplay(x, y, z);
    this->SetDisplayPoint(x, y, z);
  }
}