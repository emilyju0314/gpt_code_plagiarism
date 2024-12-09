std::vector<std::string> Tag::getTags() const {
    std::vector<std::string> v;
    std::vector<std::string>::const_iterator it;
    for(it = strings.begin(); it != strings.end(); it++){
        v.push_back(*it);
    }
    return v;
}