vtkCubeAxesActor::vtkCubeAxesActor()
{
  this->Bounds[0] = -1.0; this->Bounds[1] = 1.0;
  this->Bounds[2] = -1.0; this->Bounds[3] = 1.0;
  this->Bounds[4] = -1.0; this->Bounds[5] = 1.0;

  this->TickLocation = VTK_TICKS_INSIDE;
  this->Camera = NULL;
  this->FlyMode = VTK_FLY_CLOSEST_TRIAD;
  int i;
  for (i = 0; i < 4; i++)
    {
    this->XAxes[i] = vtkAxisActor::New();
    this->XAxes[i]->SetTickVisibility(1);
    this->XAxes[i]->SetMinorTicksVisible(1);
    this->XAxes[i]->SetLabelVisibility(1);
    this->XAxes[i]->SetTitleVisibility(1);
    this->XAxes[i]->SetAxisTypeToX();
    this->XAxes[i]->SetAxisPosition(i);

    this->YAxes[i] = vtkAxisActor::New();
    this->YAxes[i]->SetTickVisibility(1);
    this->YAxes[i]->SetMinorTicksVisible(1);
    this->YAxes[i]->SetLabelVisibility(1);
    this->YAxes[i]->SetTitleVisibility(1);
    this->YAxes[i]->SetAxisTypeToY();
    this->YAxes[i]->SetAxisPosition(i);

    this->ZAxes[i] = vtkAxisActor::New();
    this->ZAxes[i]->SetTickVisibility(1);
    this->ZAxes[i]->SetMinorTicksVisible(1);
    this->ZAxes[i]->SetLabelVisibility(1);
    this->ZAxes[i]->SetTitleVisibility(1);
    this->ZAxes[i]->SetAxisTypeToZ();
    this->ZAxes[i]->SetAxisPosition(i);
    }

  this->XLabelFormat = new char[8];
  sprintf(this->XLabelFormat, "%s", "%-#6.3g");
  this->YLabelFormat = new char[8];
  sprintf(this->YLabelFormat, "%s", "%-#6.3g");
  this->ZLabelFormat = new char[8];
  sprintf(this->ZLabelFormat, "%s", "%-#6.3g");
  this->CornerOffset = 0.0;
  this->Inertia = 1;
  this->RenderCount = 0;

  this->XAxisVisibility = 1;
  this->YAxisVisibility = 1;
  this->ZAxisVisibility = 1;

  this->XAxisTickVisibility = 1;
  this->YAxisTickVisibility = 1;
  this->ZAxisTickVisibility = 1;

  this->XAxisMinorTickVisibility = 1;
  this->YAxisMinorTickVisibility = 1;
  this->ZAxisMinorTickVisibility = 1;

  this->XAxisLabelVisibility = 1;
  this->YAxisLabelVisibility = 1;
  this->ZAxisLabelVisibility = 1;

  this->DrawXGridlines = 0;
  this->DrawYGridlines = 0;
  this->DrawZGridlines = 0;

  this->XTitle = new char[7];
  sprintf(this->XTitle, "%s", "X-Axis");
  this->XUnits = NULL;
  this->YTitle = new char[7];
  sprintf(this->YTitle, "%s", "Y-Axis");
  this->YUnits = NULL;
  this->ZTitle = new char[7];
  sprintf(this->ZTitle, "%s", "Z-Axis");
  this->ZUnits = NULL;

  this->ActualXLabel = 0;
  this->ActualYLabel = 0;
  this->ActualZLabel = 0;

  this->LastXPow = 0;
  this->LastYPow = 0;
  this->LastZPow = 0;
  this->LastXAxisDigits = 3;
  this->LastYAxisDigits = 3;
  this->LastZAxisDigits = 3;

  this->LastXRange[0] = VTK_FLOAT_MAX;
  this->LastXRange[1] = VTK_FLOAT_MAX;
  this->LastYRange[0] = VTK_FLOAT_MAX;
  this->LastYRange[1] = VTK_FLOAT_MAX;
  this->LastZRange[0] = VTK_FLOAT_MAX;
  this->LastZRange[1] = VTK_FLOAT_MAX;

  this->LastFlyMode = -1;
  for (i = 0; i < 4; i++)
    {
    this->RenderAxesX[i] = i;
    this->RenderAxesY[i] = i;
    this->RenderAxesZ[i] = i;
    }
  this->NumberOfAxesX = this->NumberOfAxesY = this->NumberOfAxesZ = 1;

  this->MustAdjustXValue = false;
  this->MustAdjustYValue = false;
  this->MustAdjustZValue = false;

  this->ForceXLabelReset = false;
  this->ForceYLabelReset = false;
  this->ForceZLabelReset = false;

  this->AutoLabelScaling = true;
  this->UserXPow = 0;
  this->UserYPow = 0;
  this->UserZPow = 0;

  this->XAxisRange[0] = VTK_DOUBLE_MAX;
  this->XAxisRange[1] = VTK_DOUBLE_MAX;
  this->YAxisRange[0] = VTK_DOUBLE_MAX;
  this->YAxisRange[1] = VTK_DOUBLE_MAX;
  this->ZAxisRange[0] = VTK_DOUBLE_MAX;
  this->ZAxisRange[1] = VTK_DOUBLE_MAX;
}