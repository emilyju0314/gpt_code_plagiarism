inline
      void writeFile(SystemVector& values,
                     std::string filename,
                     bool writeParallel = true,
                     bool writeAs3dVector = false)
      {
        writeFile(&values, filename, writeParallel, writeAs3dVector);
      }