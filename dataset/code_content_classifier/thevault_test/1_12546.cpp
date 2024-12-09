double* vtkViewport::GetCenter()
{
  if (this->VTKWindow)
  {
    // get physical window dimensions
    const int* size = this->GetVTKWindow()->GetSize();
    if (size)
    {
      this->Center[0] = ((this->Viewport[2] + this->Viewport[0]) / 2.0 * size[0]);
      this->Center[1] = ((this->Viewport[3] + this->Viewport[1]) / 2.0 * size[1]);
    }
  }
  else
  {
    this->Center[0] = this->Center[1] = 0;
  }

  return this->Center;
}