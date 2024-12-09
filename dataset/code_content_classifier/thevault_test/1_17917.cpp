void remove_vowelless() {
    word_occ ptr;

    // catalogue starting data for analysis purposes
    std::cout << "Removing voweless." << '\n';
    std::cout << "Starting list size is: " << words_vector.size() << '\n';
    int start = words_vector.size();

    // go through each word in the vector
    for (std::vector<word_occ>::iterator it = words_vector.begin(); it != words_vector.end(); ++it) {
        ptr = *it;

        // convert strings into c-strings to check individual characters within them
        const char* wordc = ptr.word.c_str();
        int vowel_check = 0;

        // check for the presence of a vowel
        // if found, stop searching and move on
        for (int i = 0; i < strlen(wordc); i++) {
            if (wordc[i] == 'a' || wordc[i] == 'e' || wordc[i] == 'i' || wordc[i] == 'o' || wordc[i] == 'u' || wordc[i] == 'y') {
                vowel_check = 1;
                break;
            }
        }

        // if no vowels were found, remove that word from the vector, and continue to the next word
        if (vowel_check == 0) {
            words_vector.erase(it);
        } 
    }


    // output how many words remain and the amount of words removed for analysis purposes
    std::cout << "Size after removing vowelless is: " << words_vector.size() << '\n';
    int diff = start - words_vector.size();
    std::cout << "---Removed " << diff << " entries" << '\n' << "==========================================================" << '\n' << '\n';
}