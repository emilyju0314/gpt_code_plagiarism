void remove_placenames() {
    word_occ ptr;

    // catalogue starting data for analysis purposes
    std::cout << "Removing placenames." << '\n';
    std::cout << "Starting list size is: " << words_vector.size() << '\n';
    int start = words_vector.size();

    // create new vector of placenames, this will go out of scope when the function completes
    std::vector<std::string> placenames;
    std::ifstream placenames_list;
    placenames_list.open("placenames.txt");

    std::string line;
    std::string place;
    while (getline(placenames_list, line)) {
        std::istringstream ss(line);
        ss >> place;

        placenames.push_back(place);
    }

    // for each word in the master list, check if it also exists in the list of placenames
    for (std::vector<word_occ>::iterator it = words_vector.begin(); it != words_vector.end(); ++it) {
        ptr = *it;

        std::string this_word = ptr.word;

        // if so, delete it
        if (std::find(placenames.begin(), placenames.end(), this_word) != placenames.end()) {
            words_vector.erase(it);
        }
    }

    // output how many words remain and the amount of words removed for analysis purposes
    std::cout << "Size after removing place names: " << words_vector.size() << '\n';
    int diff = start - words_vector.size();
    std::cout << "---Removed " << diff << " entries" << '\n' << "==========================================================" << '\n' << '\n';
}