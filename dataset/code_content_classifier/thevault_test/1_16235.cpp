int ZoltanFunctions::box_getNumObj(void* data, int* ierr)
    {
      FUNCNAME("ZoltanFunctions::box_getNumObj()");

      ZoltanPartitioner* zoltan = (ZoltanPartitioner*)data;
      map<int, bool>& elInRank = zoltan->getElementInRank();

      int nObjects = 0;
      for (map<int, bool>::iterator it = elInRank.begin(); it != elInRank.end(); ++it)
        if (it->second)
          nObjects++;

      TEST_EXIT_DBG(nObjects % 6 == 0)("Should not happen!\n");

      nObjects = nObjects / 6;

      *ierr = ZOLTAN_OK;

      return nObjects;
    }