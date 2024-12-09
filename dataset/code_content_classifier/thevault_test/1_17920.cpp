void remove_missing_bigrams() {
    word_occ ptr;

    // catalogue starting data for analysis purposes
    std::cout << "Removing non-english bigrams." << '\n';
    std::cout << "Starting list size is: " << words_vector.size() << '\n';
    int start = words_vector.size();

    std::ifstream bigrams_list;
    bigrams_list.open("unique_missing_bigrams.txt");

    std::string line;
    std::string bigram;

    std::vector<std::string> disallowed_bigrams;

    while (getline(bigrams_list, line)) {
        std::istringstream ss(line);
        ss >> bigram;
        disallowed_bigrams.push_back(bigram);
    }

    for (std::vector<word_occ>::iterator it = words_vector.begin(); it != words_vector.end(); ++it) {
        ptr = *it;
        const char* wordc = ptr.word.c_str();

        std::string rb = ""; // reference bigram

        for (int i = 0; i < strlen(wordc); i++) {
            rb = rb + wordc[i];
            if (rb.length() == 2) {
                if (std::find(disallowed_bigrams.begin(), disallowed_bigrams.end(), rb) != disallowed_bigrams.end()) {
                    words_vector.erase(it);
                }
                rb = "";
                rb = rb + wordc[i];
            }
        }
    }

    // output how many words remain and the amount of words removed for analysis purposes
    std::cout << "Size after removing non-english bigrams: " << words_vector.size() << '\n';
    int diff = start - words_vector.size();
    std::cout << "---Removed " << diff << " entries" << '\n' << "==========================================================" << '\n' << '\n';    
}