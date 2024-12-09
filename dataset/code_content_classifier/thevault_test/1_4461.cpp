void vtkCubeAxesActor::AdjustTicksComputeRange(vtkAxisActor *axes[4],
    double boundsMin, double boundsMax)
{
  double sortedRange[2], range;
  double fxt, fnt, frac;
  double div, major, minor;
  double majorStart, minorStart;
  int numTicks;
  double *inRange = axes[0]->GetRange();

  sortedRange[0] = inRange[0] < inRange[1] ? inRange[0] : inRange[1];
  sortedRange[1] = inRange[0] > inRange[1] ? inRange[0] : inRange[1];

  range = sortedRange[1] - sortedRange[0];

  // Find the integral points.
  double pow10 = log10(range);

  // Build in numerical tolerance
  if (pow10 != 0.)
    {
    double eps = 10.0e-10;
    pow10 = this->FSign((fabs(pow10) + eps), pow10);
    }

  // FFix move you in the wrong direction if pow10 is negative.
  if (pow10 < 0.)
    {
    pow10 = pow10 - 1.;
    }

  fxt = pow(10., this->FFix(pow10));

  // Find the number of integral points in the interval.
  fnt  = range/fxt;
  fnt  = this->FFix(fnt);
  frac = fnt;
  numTicks = frac <= 0.5 ? static_cast<int>(this->FFix(fnt)) : static_cast<int>(this->FFix(fnt) + 1);

  div = 1.;
  if (numTicks < 5)
    {
    div = 2.;
    }
  if (numTicks <= 2)
    {
    div = 5.;
    }

  // If there aren't enough major tick points in this decade, use the next
  // decade.
  major = fxt;
  if (div != 1.)
    {
    major /= div;
    }
  minor = (fxt/div) / 10.;

  // Figure out the first major and minor tick locations, relative to the
  // start of the axis.
  if (sortedRange[0] <= 0.)
    {
    majorStart = major*(this->FFix(sortedRange[0]*(1./major)) + 0.);
    minorStart = minor*(this->FFix(sortedRange[0]*(1./minor)) + 0.);
    }
  else
    {
    majorStart = major*(this->FFix(sortedRange[0]*(1./major)) + 1.);
    minorStart = minor*(this->FFix(sortedRange[0]*(1./minor)) + 1.);
    }

  for (int i = 0; i < 4; i++)
    {
    axes[i]->SetMinorRangeStart(minorStart);
    axes[i]->SetMajorRangeStart(majorStart);
    axes[i]->SetDeltaRangeMinor(minor);
    axes[i]->SetDeltaRangeMajor(major);
    }

  double t;
  t = (minorStart - sortedRange[0])/range;
  minorStart = t * boundsMax + (1-t) * boundsMin;
  t = (majorStart - sortedRange[0])/range;
  majorStart = t * boundsMax + (1-t) * boundsMin;
  const double scale = (boundsMax - boundsMin) / range;
  minor *= scale;
  major *= scale;

  for (int i = 0; i < 4; i++)
    {
    axes[i]->SetMinorStart(minorStart);
    axes[i]->SetMajorStart(majorStart);

    axes[i]->SetDeltaMinor(minor);
    axes[i]->SetDeltaMajor(major);
    }
}