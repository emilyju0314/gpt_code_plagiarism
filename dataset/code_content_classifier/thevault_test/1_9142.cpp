TEST_F(rocksdb_Open, QueryDB) {
    rocksdb::Options options;
    options.create_if_missing = true;  // intentionally

    EXPECT_OUTCOME_TRUE_2(db, rocksdb::create(getPathString(), options));
    EXPECT_TRUE(db) << "db is nullptr";

    std::string strNamespacePrefix = "/namespace/k/";
    std::string strDataToSearch = "abc";

    std::vector<std::string> strDataList;
    strDataList.push_back("aaa");
    strDataList.push_back(strDataToSearch);
    strDataList.push_back("abb");
    strDataList.push_back("fgd");
    strDataList.push_back("ab");
    strDataList.push_back("bdw");
    strDataList.push_back("bqc");
  
    // Fill data
    const int numberOfDataset = 1000;
    Buffer key, value;
    for (int i = 0; i < numberOfDataset; ++i)
    {
      for (const auto& str : strDataList)
      {
        key.clear();
        key.put(strNamespacePrefix + str + std::to_string(i));
        value.clear();
        value.put(str + std::to_string(i));
        EXPECT_OUTCOME_TRUE_1(db->put(key, value));
      }
    }

    Buffer prefix;
    prefix.put(strNamespacePrefix + strDataToSearch);
    EXPECT_OUTCOME_TRUE(queryResult, db->query(prefix));
    
    EXPECT_TRUE(queryResult.size() == numberOfDataset);

  }