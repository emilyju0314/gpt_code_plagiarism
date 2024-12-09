inline int readMetaData(std::string filename,
                              std::map<int, int>& elInRank,
                              std::map<int, int>& elCodeSize)
      {
        std::string tmp;
        return readMetaData(filename, elInRank, elCodeSize, tmp);
      }