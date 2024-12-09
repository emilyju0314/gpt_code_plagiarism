#include <iostream>
#include <string>

bool isValidWord(const std::string& word) {
    if(word.size() == 5 && (word.substr(3) == "lios" || word.substr(3) == "liala")) {
        return true; // Adjective
    } else if(word.size() == 4 && (word.substr(3) == "etr" || word.substr(3) == "etra")) {
        return true; // Noun
    } else if(word.size() == 7 && (word.substr(5) == "initis" || word.substr(5) == "inites")) {
        return true; // Verb
    } else {
        return false;
    }
}

int main() {
    std::string sentence;
    std::getline(std::cin, sentence);

    std::string word = "";
    bool seenNoun = false;

    for(size_t i = 0; i < sentence.size(); ++i) {
        if(sentence[i] == ' ') {
            if(!isValidWord(word)) {
                std::cout << "NO" << std::endl;
                return 0;
            }

            if(word.size() >= 4) {
                if(word.substr(3) == "etr" || word.substr(3) == "etra") {
                    seenNoun = true;
                } else if(seenNoun) {
                    std::cout << "NO" << std::endl;
                    return 0;
                }
            }

            word = "";
        } else {
            word += sentence[i];
        }
    }

    if(!isValidWord(word)) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    if(word.size() >= 4 && (word.substr(3) == "etr" || word.substr(3) == "etra")) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}