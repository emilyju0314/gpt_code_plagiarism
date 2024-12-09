inline
      void readFile(std::string filename,
                    SystemVector* sysVec,
                    bool writeParallel = WRITE_PARALLEL,
                    int nProcs = -1)
      {
        std::vector<DOFVector<double>*> vecs;
        for (int i = 0; i < sysVec->getSize(); i++)
          vecs.push_back(sysVec->getDOFVector(i));
        readFile(filename, vecs, writeParallel, nProcs);
      }