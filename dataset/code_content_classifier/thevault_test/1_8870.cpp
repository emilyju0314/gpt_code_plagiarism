inline void trim_in_place(std::string& inputString) {
    inputString.erase(inputString.begin(), 
                      std::find_if(inputString.begin(), inputString.end(),
                                   [](unsigned char c){return !std::isspace(c);}));
    auto lastChar = std::find_if(inputString.rbegin(), inputString.rend(),
                                 [](unsigned char c) {return !std::isspace(c);});

    if (lastChar != inputString.rend()) {
        inputString.erase(std::next(lastChar).base(), inputString.end());
    }
}