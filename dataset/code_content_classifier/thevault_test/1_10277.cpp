String
    ShaderManager::readStringFromFile(String const& rFullFilePath)
    {
        String result;
        std::ifstream file(rFullFilePath);

        if (!file)
            throw std::exception(String("IO error: Unable to open file %").arg(rFullFilePath).c_str());

        // Get shader source
        result.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

        return result;
    }