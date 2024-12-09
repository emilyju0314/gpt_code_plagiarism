void writeFile(DOFVector<double>* vec0,
                    std::string filename,
                    bool writeParallel,
                    Cpsformat cps,
                    std::string dataformat)
      {
        std::vector<DOFVector<double>*> vecs;
        vecs.push_back(vec0);
        detail::write(filename, NULL, vecs, writeParallel, cps, dataformat);
      }