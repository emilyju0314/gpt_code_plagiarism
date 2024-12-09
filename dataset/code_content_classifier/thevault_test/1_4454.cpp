int vtkCubeAxesActor::RenderOpaqueGeometry(vtkViewport *viewport)
{
  int i, renderedSomething=0;
  static bool initialRender = true;
  // Initialization
  if (!this->Camera)
    {
    vtkErrorMacro(<<"No camera!");
    this->RenderSomething = 0;
    return 0;
    }

  this->BuildAxes(viewport);

  if (initialRender)
    {
    for (i = 0; i < 4; i++)
      {
      this->XAxes[i]->BuildAxis(viewport, true);
      this->YAxes[i]->BuildAxis(viewport, true);
      this->ZAxes[i]->BuildAxis(viewport, true);
      }
    }
  initialRender = false;

  this->DetermineRenderAxes(viewport);

  //Render the axes
  if (this->XAxisVisibility)
    {
    for (i = 0; i < this->NumberOfAxesX; i++)
      {
      renderedSomething +=
        this->XAxes[this->RenderAxesX[i]]->RenderOpaqueGeometry(viewport);
      }
    }

  if (this->YAxisVisibility)
    {
    for (i = 0; i < this->NumberOfAxesY; i++)
      {
      renderedSomething +=
        this->YAxes[this->RenderAxesY[i]]->RenderOpaqueGeometry(viewport);
      }
    }

  if (this->ZAxisVisibility)
    {
    for (i = 0; i < this->NumberOfAxesZ; i++)
      {
      renderedSomething +=
        this->ZAxes[this->RenderAxesZ[i]]->RenderOpaqueGeometry(viewport);
      }
    }
  return renderedSomething;
}