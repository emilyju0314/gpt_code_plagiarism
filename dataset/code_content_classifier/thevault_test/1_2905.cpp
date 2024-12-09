void Authentication::setup()
    {
        rapidjson::Document doc = tools::getDOMTree(tools::getWholeFile(KEY_FILE));
        key = doc["paper-trading-id"].GetString();
        secretKey = doc["secret-key"].GetString();
        watsonKey = doc["watson-api-key"].GetString();

        std::cout << "Found API key: " << key << std::endl;
        std::cout << "Found secret key: " << secretKey << std::endl;
    }