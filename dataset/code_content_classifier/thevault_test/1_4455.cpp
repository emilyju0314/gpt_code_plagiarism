void vtkCubeAxesActor::ReleaseGraphicsResources(vtkWindow *win)
{
  for (int i = 0; i < 4; i++)
    {
    this->XAxes[i]->ReleaseGraphicsResources(win);
    this->YAxes[i]->ReleaseGraphicsResources(win);
    this->ZAxes[i]->ReleaseGraphicsResources(win);
    }
}