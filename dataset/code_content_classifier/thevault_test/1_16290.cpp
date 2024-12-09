inline void writeFile(SystemVector* sysVec,
                            std::string filename,
                            bool writeParallel = true)
      {
        std::vector<DOFVector<double>*> vecs;
        for (int i = 0; i < sysVec->getSize(); i++)
          vecs.push_back(sysVec->getDOFVector(i));
        detail::write(filename, NULL, vecs, writeParallel);
      }