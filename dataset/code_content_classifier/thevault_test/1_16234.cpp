int ZoltanFunctions::getNumObj(void* data, int* ierr)
    {
      ZoltanPartitioner* zoltan = (ZoltanPartitioner*)data;
      map<int, bool>& elInRank = zoltan->getElementInRank();

      int nObjects = 0;
      for (map<int, bool>::iterator it = elInRank.begin(); it != elInRank.end(); ++it)
        if (it->second)
          nObjects++;

      *ierr = ZOLTAN_OK;

      return nObjects;
    }