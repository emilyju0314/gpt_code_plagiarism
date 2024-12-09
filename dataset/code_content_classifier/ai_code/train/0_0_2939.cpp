#include <iostream>
#include <vector>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> words(N);
    for (int i = 0; i < N; i++) {
        std::cin >> words[i];
    }

    // Remove redundant continuous subsequences
    std::vector<std::string> compressed_words;
    compressed_words.push_back(words[0]);
    char last_char = words[0].back();
    for (int i = 1; i < N; i++) {
        if (words[i][0] != last_char) {
            compressed_words.push_back(words[i]);
            last_char = words[i].back();
        }
    }

    int L = compressed_words.size();
    std::cout << L << std::endl;

    return 0;
}