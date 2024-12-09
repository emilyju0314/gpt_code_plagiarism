void vtkCubeAxesActor::AdjustValues(const double xRange[2],
                                    const double yRange[2],
                                    const double zRange[2])
{
  char xTitle[64];

  int xPow, yPow, zPow;

  if (AutoLabelScaling)
    {
    xPow = this->LabelExponent(xRange[0], xRange[1]);
    yPow = this->LabelExponent(yRange[0], yRange[1]);
    zPow = this->LabelExponent(zRange[0], zRange[1]);
    }
  else
    {
    xPow = UserXPow;
    yPow = UserYPow;
    zPow = UserZPow;
    }

  if (xPow != 0)
    {
    if (!this->MustAdjustXValue || this->LastXPow != xPow)
      {
      this->ForceXLabelReset = true;
      }
    else
      {
      this->ForceXLabelReset = false;
      }
    this->MustAdjustXValue = true;

    if (XUnits == NULL || XUnits[0] == '\0')
      {
      sprintf(xTitle, "%s (x10^%d)", this->XTitle, xPow);
      }
    else
      {
      sprintf(xTitle, "%s (x10^%d %s)", this->XTitle, xPow, XUnits);
      }
    }
  else
    {
    if (this->MustAdjustXValue)
      {
      this->Modified();
      this->ForceXLabelReset = true;
      }
    else
      {
      this->ForceXLabelReset = false;
      }
    this->MustAdjustXValue = false;

    if (XUnits == NULL || XUnits[0] == '\0')
      {
      sprintf(xTitle,"%s",this->XTitle);
      }
    else
      {
      sprintf(xTitle, "%s (%s)", this->XTitle, XUnits);
      }
    }

  char yTitle[64];
  if (yPow != 0)
    {
    if (!this->MustAdjustYValue || this->LastYPow != yPow)
      {
      this->ForceYLabelReset = true;
      }
    else
      {
      this->ForceYLabelReset = false;
      }
    this->MustAdjustYValue = true;
    if (YUnits == NULL || YUnits[0] == '\0')
      {
      sprintf(yTitle, "%s (x10^%d)", this->YTitle, yPow);
      }
    else
      {
      sprintf(yTitle, "%s (x10^%d %s)", this->YTitle, yPow, YUnits);
      }
    }
  else
    {
    if (this->MustAdjustYValue)
      {
      this->Modified();
      this->ForceYLabelReset = true;
      }
    else
      {
      this->ForceYLabelReset = false;
      }
    this->MustAdjustYValue = false;
    if (YUnits == NULL || YUnits[0] == '\0')
      {
      sprintf(yTitle,"%s",this->YTitle);
      }
    else
      {
      sprintf(yTitle, "%s (%s)", this->YTitle, YUnits);
      }
    }

  char zTitle[64];
  if (zPow != 0)
    {
    if (!this->MustAdjustZValue || this->LastZPow != zPow)
      {
      this->ForceZLabelReset = true;
      }
    else
      {
      this->ForceZLabelReset = false;
      }
    this->MustAdjustZValue = true;

    if (ZUnits == NULL || ZUnits[0] == '\0')
      {
      sprintf(zTitle, "%s (x10^%d)", this->ZTitle, zPow);
      }
    else
      {
      sprintf(zTitle, "%s (x10^%d %s)", this->ZTitle, zPow, ZUnits);
      }
    }
  else
    {
    if (this->MustAdjustZValue)
      {
      this->Modified();
      this->ForceZLabelReset = true;
      }
    else
      {
      this->ForceZLabelReset = false;
      }
    this->MustAdjustZValue = false;

    if (ZUnits == NULL || ZUnits[0] == '\0')
      {
      sprintf(zTitle,"%s",this->ZTitle);
      }
    else
      {
      sprintf(zTitle, "%s (%s)", this->ZTitle, ZUnits);
      }
    }

  this->LastXPow = xPow;
  this->LastYPow = yPow;
  this->LastZPow = zPow;

  this->SetActualXLabel(xTitle);
  this->SetActualYLabel(yTitle);
  this->SetActualZLabel(zTitle);
}