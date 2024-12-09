inline
      void readFile(std::string filename, DOFVector<double>& dofVector)
      {
        readFile(filename, &dofVector);
      }