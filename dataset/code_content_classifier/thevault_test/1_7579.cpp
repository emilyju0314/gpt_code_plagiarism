void ArrayRemoveDuplicates(std::vector<std::string> &s) {
    std::unordered_map<std::string, bool> found;
    found.reserve(s.size());
    int j = 0;
    for (const std::string& it : s) {
        if (!found[it]) {
            found[it] = true;
            s[j++] = it;
        }
    }
    s.erase(s.begin() + j, s.end());
}