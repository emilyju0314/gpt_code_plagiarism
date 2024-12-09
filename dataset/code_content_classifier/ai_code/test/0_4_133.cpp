#include <iostream>
#include <vector>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<std::string> bigrams(n-2);
        for (int i = 0; i < n-2; i++) {
            std::cin >> bigrams[i];
        }

        // Find the missing bigram
        std::string missing_bigram;
        for (int i = 0; i < n-2; i++) {
            if (bigrams[i] == bigrams[i+1]) {
                missing_bigram = bigrams[i];
                break;
            }
        }

        // Reconstruct the word
        std::string word = missing_bigram.substr(0, 1);
        for (int i = 0; i < n-2; i++) {
            if (bigrams[i] == missing_bigram) {
                word += missing_bigram.substr(1, 1);
            } else {
                word += bigrams[i];
            }
        }
        word += missing_bigram.substr(1, 1);

        std::cout << word << "\n";
    }

    return 0;
}