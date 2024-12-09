#include <iostream>
#include <string>

bool isValidWord(std::string word) {
    if (word.length() < 3) {
        return false;
    }
    
    if ((word.substr(word.length()-5, 5) == "lios" || word.substr(word.length()-6, 6) == "liala") && word.length() >= 5) {
        return true;
    }
    
    if ((word.substr(word.length()-3, 3) == "etr" || word.substr(word.length()-4, 4) == "etra") && word.length() >= 3) {
        return true;
    }
    
    if ((word.substr(word.length()-6, 6) == "initis" || word.substr(word.length()-6, 6) == "inites") && word.length() >= 6) {
        return true;
    }
    
    return false;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    std::string word;
    bool isValid = true;
    int adjCount = 0, nounCount = 0, verbCount = 0;
    bool hasAdj = false, hasNoun = false, hasVerb = false;
    
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            word += input[i];
        } else {
            if (!isValidWord(word)) {
                isValid = false;
                break;
            }
            
            if (word.substr(word.length()-5, 5) == "lios" || word.substr(word.length()-6, 6) == "liala") {
                adjCount++;
                hasAdj = true;
            } else if (word.substr(word.length()-3, 3) == "etr" || word.substr(word.length()-4, 4) == "etra") {
                nounCount++;
                hasNoun = true;
            } else if (word.substr(word.length()-6, 6) == "initis" || word.substr(word.length()-6, 6) == "inites") {
                verbCount++;
                hasVerb = true;
            }
            
            if ((hasAdj && hasNoun) || (hasNoun && hasVerb)) {
                isValid = false;
                break;
            }
            
            word = "";
        }
    }
    
    if (!isValidWord(word)) {
        isValid = false;
    } else {
        if (word.substr(word.length()-5, 5) == "lios" || word.substr(word.length()-6, 6) == "liala") {
            adjCount++;
            hasAdj = true;
        } else if (word.substr(word.length()-3, 3) == "etr" || word.substr(word.length()-4, 4) == "etra") {
            nounCount++;
            hasNoun = true;
        } else if (word.substr(word.length()-6, 6) == "initis" || word.substr(word.length()-6, 6) == "inites") {
            verbCount++;
            hasVerb = true;
        }
    }

    if (hasAdj && hasNoun && hasVerb) {
        isValid = false;
    }

    if ((adjCount > 0 && nounCount > 0 && verbCount > 0) && (hasAdj || hasNoun || hasVerb) && isValid) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}