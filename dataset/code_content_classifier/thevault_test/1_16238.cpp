void writeFile(Mesh* mesh,
                    std::string filename,
                    bool writeParallel,
                    Cpsformat cps,
                    std::string dataformat)
      {
        std::vector<DOFVector<double>*> vecs;
        detail::write(filename, mesh, vecs, writeParallel, cps, dataformat);
      }