inline
      void readFile(std::string filename,
                    SystemVector& sysVec,
                    bool writeParallel = WRITE_PARALLEL,
                    int nProcs = -1)
      {
        readFile(filename, &sysVec, writeParallel, nProcs);
      }