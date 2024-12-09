void Points::sort()
{
  //List not yet loaded, wait
  //if (!sorter.buffer || !total == 0 || elements == 0 || !view->is3d) return;
  if (!sorter.buffer || total == 0) return;

  clock_t t1,t2;
  t1 = clock();

  //Calculate min/max distances from view plane
  float distanceRange[2];
  view->getMinMaxDistance(min, max, distanceRange, true);

  //Update eye distances, clamping distance to integer between 0 and USHRT_MAX-1
  //float multiplier = (float)USHRT_MAX / (distanceRange[1] - distanceRange[0]);
  float multiplier = (USHRT_MAX-1.0) / (distanceRange[1] - distanceRange[0]);
  float fdistance;
  unsigned int opaqueCount = 0;
  for (unsigned int i = 0; i < elements; i++)
  {
    //Max dist 65535 reserved for opaque triangles
    if (sorter.buffer[i].distance < USHRT_MAX)
    {
      //Distance from viewing plane is -eyeZ
      fdistance = view->eyePlaneDistance(sorter.buffer[i].vertex);
      //fdistance = view->eyeDistance(sorter.buffer[i].vertex);
      //float d = floor(multiplier * (fdistance - distanceRange[0])) + 0.5;
      //assert(d < USHRT_MAX);
      //assert(d >= 0);
      sorter.buffer[i].distance = (unsigned short)(multiplier * (fdistance - distanceRange[0]));
    }
    else
      opaqueCount++;
  }
  t2 = clock();
  debug_print("  %.4lf seconds to calculate distances\n", (t2-t1)/(double)CLOCKS_PER_SEC);
  t1 = clock();

  //Skip sort if all opaque
  if (opaqueCount == elements)
  {
    debug_print("No sort necessary\n");
    return;
  }

  //Depth sort using 2-byte key radix sort, 10 times faster than equivalent quicksort
  if (view->is3d)
  {
    sorter.sort(elements);
    t2 = clock();
    debug_print("  %.4lf seconds to sort %d points\n", (t2-t1)/(double)CLOCKS_PER_SEC, elements);
  }

  //Re-map vertex indices in sorted order
  t1 = clock();
  //Lock the update mutex, to allow updating the indexlist and prevent access while drawing
  LOCK_GUARD(loadmutex);
  //Reverse order farthest to nearest
  //int distSample = session.global("pointdistsample");
  //uint32_t SEED;
  int idxcount = 0;
  for(int i=elements-1; i>=0; i--)
  {
    /*/Distance based sub-sampling - disabled
    if (distSample > 0)
    {
      SEED = sorter.buffer[i].index; //Reset the seed for determinism based on index
      int subSample = 1 + distSample * sorter.buffer[i].distance / (USHRT_MAX-1.0); //[1,distSample]
      if (subSample > 1 && SHR3(SEED) % subSample > 0) continue;
    }*/
    sorter.indices[idxcount] = sorter.buffer[i].index;
    idxcount ++;
  }

  t2 = clock();
  //if (distSample)
  //  debug_print("  %.4lf seconds to load %d indices (dist-sub-sampled %d)\n", (t2-t1)/(double)CLOCKS_PER_SEC, idxcount, distSample);
  //else
    debug_print("  %.4lf seconds to load %d indices)\n", (t2-t1)/(double)CLOCKS_PER_SEC, idxcount);
  t1 = clock();

  //Force update after sort
  sorter.changed = true;
}