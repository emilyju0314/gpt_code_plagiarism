static bool hash_all_strings_up_to_len(std::string search_space, int length, std::string prepend, std::string to_find) {
    for (int i = 0; i <= length-((int)prepend.size()); i++) {
        if (hash_all_strings(search_space, i, prepend, to_find)) {
            return true;
        }
    }
    return false;
}