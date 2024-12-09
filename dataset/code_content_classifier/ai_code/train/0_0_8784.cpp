#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::unordered_map<std::string, std::string> language1, language2;
    for (int i = 0; i < m; i++) {
        std::string word1, word2;
        std::cin >> word1 >> word2;
        language1[word1] = word2;
        language2[word2] = word1;
    }

    std::vector<std::string> lecture(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lecture[i];
    }

    for (int i = 0; i < n; i++) {
        std::string word = lecture[i];
        if (word.length() <= language2[language1[word]].length()) {
            std::cout << word << " ";
        } else {
            std::cout << language2[language1[word]] << " ";
        }
    }

    return 0;
}