int* vtkViewport::GetOrigin()
{
  if (this->VTKWindow)
  {
    const int* winSize = this->VTKWindow->GetSize();

    // Round the origin up a pixel
    this->Origin[0] = static_cast<int>(this->Viewport[0] * static_cast<double>(winSize[0]) + 0.5);
    this->Origin[1] = static_cast<int>(this->Viewport[1] * static_cast<double>(winSize[1]) + 0.5);
  }
  else
  {
    this->Origin[0] = this->Origin[1] = 0;
  }

  return this->Origin;
}