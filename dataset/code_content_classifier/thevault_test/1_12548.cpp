int* vtkVRRenderWindow::GetScreenSize()
{
  if (this->GetSizeFromAPI())
  {
    this->ScreenSize[0] = this->Size[0];
    this->ScreenSize[1] = this->Size[1];
  }
  return this->ScreenSize;
}