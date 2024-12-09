inline void writeFile(std::vector<DOFVector<double>*> vecs,
                            std::string filename,
                            bool writeParallel = true)
      {
        detail::write(filename, NULL, vecs, writeParallel);
      }