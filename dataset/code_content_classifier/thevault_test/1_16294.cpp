inline void writeFile(Mesh* mesh,
                            std::string filename,
                            bool writeParallel = true)
      {
        std::vector<DOFVector<double>*> vecs;
        detail::write(filename, mesh, vecs, writeParallel);
      }