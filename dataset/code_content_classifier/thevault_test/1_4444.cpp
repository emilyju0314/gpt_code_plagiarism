inline unsigned char *vtkLinearLookup(double v,
                                      unsigned char *table,
                                      double maxIndex,
                                      double shift, double scale,
                                      unsigned char *nanColor)
{
  if (vtkMath::IsNan(v))
    {
    return nanColor;
    }

  double findx = (v + shift)*scale;
  if (findx < 0.0)
    {
    findx = 0.0;
    }
  else if (findx > maxIndex)
    {
    findx = maxIndex;
    }
  return &table[4*static_cast<unsigned int>(findx)];
  /* round
  return &table[4*(unsigned int)(findx + 0.5f)];
  */
}