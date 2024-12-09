void remove_triple_letters() {
    word_occ ptr;

    // catalogue starting data for analysis purposes
    std::cout << "Removing triple letter occurences." << '\n';
    std::cout << "Starting list size is: " << words_vector.size() << '\n';
    int start = words_vector.size();

    // go through each word in the vector
    for (std::vector<word_occ>::iterator it = words_vector.begin(); it != words_vector.end(); ++it) {
        ptr = *it;

        // convert strings into c-strings to check individual characters within them
        const char* wordc = ptr.word.c_str();

        // create trackers for consecutive letters. One to keep track of the last letter, and a count of the current streak of consecutive letters
        int consecutive_letters = 1;
        char check_letter;
        for (int i = 0; i < strlen(wordc); i++) {
            // if the current letter matches the previous one, increase the count
            if (wordc[i] == check_letter) {
                consecutive_letters++;
                // if that count exceeds three, remove the word and break from the loop
                if (consecutive_letters >= 3) {
                    words_vector.erase(it);
                    break;
                }
            } else { // if the current letter does not match the last one, reset the count
                consecutive_letters = 1;
            }
            // update the previous letter
            check_letter = wordc[i];
        }
    }

    // output how many words remain and the amount of words removed for analysis purposes
    std::cout << "Size after removing words with 3 or more consecutive letters is: " << words_vector.size() << '\n';
    int diff = start - words_vector.size();
    std::cout << "---Removed " << diff << " entries" << '\n' << "==========================================================" << '\n' << '\n';
}