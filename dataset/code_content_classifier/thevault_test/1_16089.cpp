TagList(std::initializer_list<std::pair<std::string, std::string>> tags)
    {
        const std::pair<std::string, std::string>* tagData = tags.begin();
        for (size_t t = 0; t < tags.size(); t++) {
            set(tagData[t].first, tagData[t].second);
        }
    }