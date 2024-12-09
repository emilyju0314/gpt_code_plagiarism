inline
      void writeFile(SystemVector* vecs,
                     std::string filename)
      {
        std::vector<DOFVector<double>*> dofVectors;
        for (int i = 0; i < vecs->getSize(); i++)
          dofVectors.push_back(vecs->getDOFVector(i));
        writeFile(dofVectors, filename);
      }