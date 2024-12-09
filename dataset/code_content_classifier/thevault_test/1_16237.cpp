void writeFile(std::vector<DOFVector<double>*> vecs,
                    std::string filename,
                    bool writeParallel,
                    Cpsformat cps,
                    std::string dataformat)
      {
        detail::write(filename, NULL, vecs, writeParallel, cps, dataformat);
      }