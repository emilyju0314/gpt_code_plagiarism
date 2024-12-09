void vtkDataSetSurfaceFilter::InsertPolygonInHash(vtkIdType* ids,
                                                  int numPts, vtkIdType sourceId)
{
  vtkFastGeomQuad *quad, **end;

  // find the index to the smallest id
  vtkIdType offset = 0;
  for(int i=1; i<numPts; i++)
    {
    if(ids[i] < ids[offset])
      {
      offset = i;
      }
    }

  // copy ids into ordered array with smallest id first
  vtkIdType* tab = new vtkIdType[numPts];
  for(int i=0; i<numPts; i++)
    {
    tab[i] = ids[(offset+i)%numPts];
    }
  
  // Look for existing hex in the hash;
  end = this->QuadHash + tab[0];
  quad = *end;
  while (quad)
    {
    end = &(quad->Next);
    // a has to match in this bin.
    // first just check the polygon size.
    bool match = true;
    if (numPts == quad->numPts)
      {
      if ( tab[1] == quad->ptArray[1])
        {
        // if the first two points match loop through forwards
        // checking all points
        for (int i = 2; i < numPts; i++)
          {
          if ( tab[i] != quad->ptArray[i])
            {
            match = false;
            break;
            }
          }
        }
      else if (tab[numPts-1] == quad->ptArray[1])
        {
        // the first two points match with the opposite sense.
        // loop though comparing the correct sense
        for (int i = 2; i < numPts; i++)
          {
          if ( tab[numPts - i] != quad->ptArray[i])
            {
            match = false;
            break;
            }
          }
        }
      else
        {
        match = false;
        }
      }
    else
      {
      match = false;
      }

      if (match)
        {
        // We have a match.
        quad->SourceId = -1;
        // That is all we need to do. Hide any tri shared by two or more cells.
        return;
        }
    quad = *end;
    }
  
  // Create a new quad and add it to the hash.
  quad = this->NewFastGeomQuad(numPts);
  // mark the structure as a polygon
  quad->Next = NULL;
  quad->SourceId = sourceId;
  for (int i = 0; i < numPts; i++)
    {
      quad->ptArray[i] = tab[i];
    }
  *end = quad;

  delete [] tab;
}