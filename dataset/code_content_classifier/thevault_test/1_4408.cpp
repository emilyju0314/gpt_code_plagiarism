int vtkImageStencilData::GetNextExtent(int &r1, int &r2,
                                       int rmin, int rmax,
                                       int yIdx, int zIdx, int &iter)
{
  int yExt = this->Extent[3] - this->Extent[2] + 1;
  int zExt = this->Extent[5] - this->Extent[4] + 1;
  yIdx -= this->Extent[2];
  zIdx -= this->Extent[4];

  // initialize r1, r2 to defaults
  r1 = rmax + 1;
  r2 = rmax;

  if (yIdx < 0 || yIdx >= yExt || zIdx < 0 || zIdx >= zExt)
    { // out-of-bounds in y or z, use null extent
    // if iter was set to negative, reverse the result
    if (iter < 0)
      {
      iter = 0;
      r1 = rmin;
      r2 = rmax;
      return 1;
      }
    return 0;
    }

  // get the ExtentList and ExtentListLength for this yIdx,zIdx
  int incr = zIdx*yExt + yIdx;
  int *clist = this->ExtentLists[incr];
  int clistlen = this->ExtentListLengths[incr];

  if (iter <= 0)
    {
    int state = 1; // start outside
    if (iter < 0)  // unless iter is negative at start
      {
      iter = 0;
      state = -1;
      }

    r1 = VTK_INT_MIN;
    for ( ; iter < clistlen; iter++)
      {
      if (clist[iter] >= rmin)
        {
        if (state > 0)
          {
          r1 = clist[iter++];
          }
        break;
        }
      state = -state;
      }
    if (r1 == VTK_INT_MIN)
      {
      r1 = rmin;
      if (state > 0)
        {
        r1 = rmax + 1;
        }
      }
    }
  else
    {
    if (iter >= clistlen)
      {
      return 0;
      }
    r1 = clist[iter++];
    if (r1 < rmin)
      {
      r1 = rmin;
      }
    }

  if (r1 > rmax)
    {
    r1 = rmax + 1;
    return 0;
    }

  if (iter >= clistlen)
    {
    return 1;
    }

  r2 = clist[iter++] - 1;

  if (r2 > rmax)
    {
    r2 = rmax;
    }

  return 1;
}