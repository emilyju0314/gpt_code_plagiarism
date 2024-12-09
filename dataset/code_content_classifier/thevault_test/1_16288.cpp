inline
      void readFile(std::string filename,
                    SystemVector* vecs)
      {
        std::vector<DOFVector<double>*> dofVectors(vecs->getSize());
        std::vector<std::string> componentNames(vecs->getSize());
        for (int i = 0; i < vecs->getSize(); i++)
        {
          dofVectors[i] = vecs->getDOFVector(i);
          componentNames[i] = vecs->getDOFVector(i)->getName();
        }
        readByName(filename, dofVectors, componentNames);
      }