void LinesSorted::sort()
{
  //Skip if nothing to render or in 2d
  if (!sorter.buffer || linecount == 0 || elements == 0) return;
  clock_t t1,t2;
  t1 = clock();
  assert(sorter.buffer);

  //Calculate min/max distances from view plane
  float distanceRange[2];
  view->getMinMaxDistance(min, max, distanceRange, true);

  //Update eye distances, clamping int distance to integer between 1 and 65534
  float multiplier = (USHRT_MAX-1.0) / (distanceRange[1] - distanceRange[0]);
  unsigned int opaqueCount = 0;
  float fdistance;
  for (unsigned int i = 0; i < linecount; i++)
  {
    //Distance from viewing plane is -eyeZ
    //Max dist 65535 reserved for opaque triangles
    if (sorter.buffer[i].distance < USHRT_MAX)
    {
      assert(sorter.buffer[i].vertex);
      fdistance = view->eyePlaneDistance(sorter.buffer[i].vertex);
      //fdistance = view->eyeDistance(sorter.buffer[i].vertex);
      fdistance = std::min(distanceRange[1], std::max(distanceRange[0], fdistance)); //Clamp to range
      sorter.buffer[i].distance = (unsigned short)(multiplier * (fdistance - distanceRange[0]));
      //if (i%10000==0) printf("%d : centroid %f %f %f\n", i, sorter.buffer[i].vertex[0], sorter.buffer[i].vertex[1], sorter.buffer[i].vertex[2]);
      //Reverse as radix sort is ascending and we want to draw by distance descending
      //sorter.buffer[i].distance = USHRT_MAX - (unsigned short)(multiplier * (fdistance - mindist));
      //assert(sorter.buffer[i].distance >= 1 && sorter.buffer[i].distance <= USHRT_MAX);
    }
    else
      opaqueCount++;
  }
  t2 = clock();
  debug_print("  %.4lf seconds to calculate distances\n", (t2-t1)/(double)CLOCKS_PER_SEC);
  t1 = clock();

  //Skip sort if all opaque
  if (opaqueCount == linecount) 
  {
    debug_print("No sort necessary\n");
    return;
  }

  if (linecount > total/2)
  {
    //Will overflow sorter.buffer buffer (this should not happen!)
    fprintf(stderr, "Too many lines! %d > %d\n", linecount, total/2);
    linecount = total/2;
  }

  if (view->is3d)
  {
    //Depth sort using 2-byte key radix sort, 10 times faster than equivalent quicksort
    sorter.sort(linecount);
    t2 = clock();
    debug_print("  %.4lf seconds to sort %d lines\n", (t2-t1)/(double)CLOCKS_PER_SEC, linecount);
  }

  //Lock the update mutex, to allow updating the indexlist and prevent access while drawing
  t1 = clock();
  LOCK_GUARD(loadmutex);
  unsigned int idxcount = 0;
  for(int i=linecount-1; i>=0; i--)
  {
    assert(idxcount < 2 * linecount * sizeof(unsigned int));
    //Copy index bytes
    memcpy(&sorter.indices[idxcount], sorter.buffer[i].index, sizeof(GLuint) * 2);
    idxcount += 2;
    //if (i%100==0) printf("%d ==> %d,%d,%d\n", i, sorter.buffer[i].index[0], sorter.buffer[i].index[1]);
  }

  t2 = clock();
  debug_print("  %.4lf seconds to save %d line indices\n", (t2-t1)/(double)CLOCKS_PER_SEC, linecount*2);

  //Force update after sort
  sorter.changed = true;
}