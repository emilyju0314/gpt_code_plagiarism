void vtkCubeAxesActor::BuildLabels(vtkAxisActor *axes[4])
{
  char label[64];
  int i, labelCount = 0;
  double deltaMajor = axes[0]->GetDeltaMajor();
  const double *p2  = axes[0]->GetPoint2Coordinate()->GetValue();
  double *range     = axes[0]->GetRange();
  double lastVal = 0, val = axes[0]->GetMajorStart();
  double extents = range[1] - range[0];
  bool mustAdjustValue = 0;
  int lastPow = 0;

  vtkStringArray *labels = vtkStringArray::New();
  const char *format = "%s";
  switch (axes[0]->GetAxisType())
    {
    case VTK_AXIS_TYPE_X:
      lastVal = p2[0];
      format = this->XLabelFormat;
      mustAdjustValue = this->MustAdjustXValue;
      lastPow = this->LastXPow;
      break;
    case VTK_AXIS_TYPE_Y:
      lastVal = p2[1];
      format = this->YLabelFormat;
      mustAdjustValue = this->MustAdjustYValue;
      lastPow = this->LastYPow;
      break;
    case VTK_AXIS_TYPE_Z:
      lastVal = p2[2];
      format = this->ZLabelFormat;
      mustAdjustValue = this->MustAdjustZValue;
      lastPow = this->LastZPow;
      break;
    }

  // figure out how many labels we need:
  while (val <= lastVal && labelCount < VTK_MAX_LABELS)
    {
    labelCount++;
    val += deltaMajor;
    }

  labels->SetNumberOfValues(labelCount);

  val = axes[0]->GetMajorRangeStart();
  deltaMajor = axes[0]->GetDeltaRangeMajor();

  double scaleFactor = 1.;
  if (lastPow != 0)
    {
    scaleFactor = 1.0/pow(10., lastPow);
    }

  for (i = 0; i < labelCount; i++)
    {
    if (fabs(val) < 0.01 && extents > 1)
      {
      // We just happened to fall at something near zero and the range is
      // large, so set it to zero to avoid ugliness.
      val = 0.;
      }
    if (mustAdjustValue)
      {
      sprintf(label, format, val*scaleFactor);
      }
    else
      {
      sprintf(label, format, val);
      }
    if (fabs(val) < 0.01)
      {
      //
      // Ensure that -0.0 is never a label
      // The maximum number of digits that we allow past the decimal is 5.
      //
      if (strcmp(label, "-0") == 0)
        {
        sprintf(label, "0");
        }
      else if (strcmp(label, "-0.0") == 0)
        {
        sprintf(label, "0.0");
        }
      else if (strcmp(label, "-0.00") == 0)
        {
        sprintf(label, "0.00");
        }
      else if (strcmp(label, "-0.000") == 0)
        {
        sprintf(label, "0.000");
        }
      else if (strcmp(label, "-0.0000") == 0)
        {
        sprintf(label, "0.0000");
        }
      else if (strcmp(label, "-0.00000") == 0)
        {
        sprintf(label, "0.00000");
        }
      }
    labels->SetValue(i, label);
    val += deltaMajor;
    }
  for (i = 0; i < 4; i++)
    {
    axes[i]->SetLabels(labels);
    }
  labels->Delete();
}