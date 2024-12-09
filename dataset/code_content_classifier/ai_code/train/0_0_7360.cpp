#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string W;
    std::string T;
    std::string word;
    int count = 0;

    // Read word W
    std::cin >> W;
    std::transform(W.begin(), W.end(), W.begin(), ::tolower);

    // Read text T
    while (std::cin >> word) {
        if (word == "END_OF_TEXT") {
            break;
        }

        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        if (word == W) {
            count++;
        }
    }

    // Print the number of W in the text
    std::cout << count << std::endl;
    
    return 0;
}