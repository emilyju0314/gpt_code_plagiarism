#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string findWord(int n, std::vector<std::string>& bigrams) {
    std::string word;
    
    // Construct the word based on the bigrams
    word = bigrams[0].substr(0, 1) + bigrams[0].substr(1, 1);
    for (int i = 1; i < n - 2; i++) {
        if (bigrams[i].substr(0, 1) == bigrams[i-1].substr(1, 1)) {
            word += bigrams[i].substr(1, 1);
        } else {
            word += bigrams[i].substr(0, 1);
        }
    }
    word += bigrams[n-3].substr(0, 1);
    
    return word;
}

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

        std::string result = findWord(n, bigrams);
        std::cout << result << std::endl;
    }

    return 0;
}