#include <iostream>
#include <string>
#include <vector>

bool containsAllKeys(const std::string& substr, const std::vector<char>& keys) {
    for (char key : keys) {
        if (substr.find(key) == std::string::npos) {
            return false;
        }
    }
    return true;
}

void findShortestSubstring(const std::string& S, const std::vector<char>& K) {
    int n = S.length();
    int k = K.size();

    int start = 0, minLen = n + 1;
    int count = 0, startIndex = 0;

    std::vector<int> freq(256, 0);

    for (int i = 0; i < n; i++) {
        if (freq[S[i]] == 0) {
            count++;
        }
        freq[S[i]]++;

        if (count == k) {
            while (freq[S[start]] > 1) {
                freq[S[start++]]--;
            }

            int len = i - start + 1;
            if (len < minLen) {
                minLen = len;
                startIndex = start;
            }
        }
    }

    if (minLen == n + 1) {
        std::cout << "0\n\n";
    } else {
        std::cout << "1\n\n";
        for (int i = startIndex; i < startIndex + minLen; i += 72) {
            std::cout << S.substr(i, 72) << std::endl;
        }
        std::cout << "\n";
    }
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break; // Exit if empty line encountered
        }

        std::string S, K;
        std::getline(std::cin, S);
        std::getline(std::cin, K);

        std::vector<char> keyChars;
        for (char c : K) {
            keyChars.push_back(c);
        }

        findShortestSubstring(S, keyChars);
    }

    return 0;
}