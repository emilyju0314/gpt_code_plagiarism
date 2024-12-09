BlockMapper(unsigned int nComp, size_type nDOFperComp)
      : nComp(nComp),
        rowOffset(0), colOffset(0),
        nrow(nComp*nDOFperComp), ncol(nrow),
        sizes(nComp)
    {
      for (unsigned int i = 0; i < nComp; ++i)
        sizes[i] = nDOFperComp;
    }