int vtkCubeAxesActor::Digits(double min, double max )
{
  double  range = max - min;
  double  pow10   = log10(range);
  int    ipow10  = static_cast<int>(floor(pow10));
  int    digitsPastDecimal = -ipow10;

  if (digitsPastDecimal < 0)
    {
    //
    // The range is more than 10, but not so big we need scientific
    // notation, we don't need to worry about decimals.
    //
    digitsPastDecimal = 0;
    }
  else
    {
    //
    // We want one more than the range since there is more than one
    // tick per decade.
    //
    digitsPastDecimal++;

    //
    // Anything more than 5 is just noise.  (and probably 5 is noise with
    // doubleing point if the part before the decimal is big).
    //
    if (digitsPastDecimal > 5)
      {
      digitsPastDecimal = 5;
      }
    }

  return digitsPastDecimal;
}