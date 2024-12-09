inline void writeFile(DOFVector<double>& vec0,
                            std::string filename,
                            bool writeParallel = true)
      {
        writeFile(&vec0, filename, writeParallel);
      }