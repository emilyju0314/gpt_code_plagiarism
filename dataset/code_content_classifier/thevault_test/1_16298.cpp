inline
      void readFile(std::string filename,
                    DOFVector<double>& vec0,
                    bool writeParallel = WRITE_PARALLEL,
                    int nProcs = -1)
      {
        readFile(filename, &vec0, NULL, NULL, writeParallel, nProcs);
      }