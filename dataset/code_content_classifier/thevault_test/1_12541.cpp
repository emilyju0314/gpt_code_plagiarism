void vtkViewport::DisplayToView()
{
  if (this->VTKWindow)
  {
    double vx, vy, vz;
    int sizex, sizey;

    /* get physical window dimensions */
    const int* size = this->VTKWindow->GetSize();
    if (size == nullptr)
    {
      return;
    }
    sizex = size[0];
    sizey = size[1];

    vx = 0.0;
    if (sizex != 0.0)
    {
      vx = 2.0 * (this->DisplayPoint[0] - sizex * this->Viewport[0]) /
          (sizex * (this->Viewport[2] - this->Viewport[0])) -
        1.0;
    }

    vy = 0.0;
    if (sizey != 0.0)
    {
      vy = 2.0 * (this->DisplayPoint[1] - sizey * this->Viewport[1]) /
          (sizey * (this->Viewport[3] - this->Viewport[1])) -
        1.0;
    }

    vz = this->DisplayPoint[2];

    this->SetViewPoint(vx, vy, vz);
  }
}