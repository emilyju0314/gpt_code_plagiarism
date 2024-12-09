bool HasEnding(const std::string& full_string, const std::string& ending) {
    if (full_string.length() >= ending.length()) {
        return (0 == full_string.compare (full_string.length() - ending.length(), ending.length(), ending));
    }
    return false;
}