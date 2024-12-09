bool vtkCubeAxesActor::ComputeTickSize(double bounds[6])
{
  bool xRangeChanged = this->LastXRange[0] != bounds[0] ||
                       this->LastXRange[1] != bounds[1];

  bool yRangeChanged = this->LastYRange[0] != bounds[2] ||
                       this->LastYRange[1] != bounds[3];

  bool zRangeChanged = this->LastZRange[0] != bounds[4] ||
                       this->LastZRange[1] != bounds[5];

  if (!(xRangeChanged || yRangeChanged || zRangeChanged))
    {
    // no need to re-compute ticksize.
    return false;
    }

  int i;
  double xExt = bounds[1] - bounds[0];
  double yExt = bounds[3] - bounds[2];
  double zExt = bounds[5] - bounds[4];

  if (xRangeChanged)
    {
    this->AdjustTicksComputeRange(this->XAxes, bounds[0], bounds[1]);
    this->BuildLabels(this->XAxes);
    }
  if (yRangeChanged)
    {
    this->AdjustTicksComputeRange(this->YAxes, bounds[2], bounds[3]);
    this->BuildLabels(this->YAxes);
    }
  if (zRangeChanged)
    {
    this->AdjustTicksComputeRange(this->ZAxes, bounds[4], bounds[5]);
    this->BuildLabels(this->ZAxes);
    }

  this->LastXRange[0] = (this->XAxisRange[0] == VTK_DOUBLE_MAX ?
                                  bounds[0] : this->XAxisRange[0]);
  this->LastXRange[1] = (this->XAxisRange[1] == VTK_DOUBLE_MAX ?
                                  bounds[1] : this->XAxisRange[1]);
  this->LastYRange[0] = (this->YAxisRange[0] == VTK_DOUBLE_MAX ?
                                  bounds[2] : this->YAxisRange[0]);
  this->LastYRange[1] = (this->YAxisRange[1] == VTK_DOUBLE_MAX ?
                                  bounds[3] : this->YAxisRange[1]);
  this->LastZRange[0] = (this->ZAxisRange[0] == VTK_DOUBLE_MAX ?
                                  bounds[4] : this->ZAxisRange[0]);
  this->LastZRange[1] = (this->ZAxisRange[1] == VTK_DOUBLE_MAX ?
                                  bounds[5] : this->ZAxisRange[1]);

  double major = 0.02 * (xExt + yExt + zExt) / 3.;
  double minor = 0.5 * major;
  for (i = 0; i < 4; i++)
    {
    this->XAxes[i]->SetMajorTickSize(major);
    this->XAxes[i]->SetMinorTickSize(minor);

    this->YAxes[i]->SetMajorTickSize(major);
    this->YAxes[i]->SetMinorTickSize(minor);

    this->ZAxes[i]->SetMajorTickSize(major);
    this->ZAxes[i]->SetMinorTickSize(minor);

    this->XAxes[i]->SetGridlineXLength(xExt);
    this->XAxes[i]->SetGridlineYLength(yExt);
    this->XAxes[i]->SetGridlineZLength(zExt);

    this->YAxes[i]->SetGridlineXLength(xExt);
    this->YAxes[i]->SetGridlineYLength(yExt);
    this->YAxes[i]->SetGridlineZLength(zExt);

    this->ZAxes[i]->SetGridlineXLength(xExt);
    this->ZAxes[i]->SetGridlineYLength(yExt);
    this->ZAxes[i]->SetGridlineZLength(zExt);
    }
  return true;
}