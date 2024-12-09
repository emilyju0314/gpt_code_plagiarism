inline
      void writeFile(DOFVector<double>* dofVector,
                     std::string filename)
      {
        std::vector<DOFVector<double>*> dofVectors;
        dofVectors.push_back(dofVector);
        writeFile(dofVectors, filename);
      }