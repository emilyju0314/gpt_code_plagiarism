#include <iostream>
#include <vector>

std::string f(std::string s) {
    return s + s;
}

int main() {
    std::string S;
    std::cin >> S;

    long long l, r;
    std::cin >> l >> r;

    std::vector<int> occurrences(26, 0);
    int currentLength = S.length();

    for (char c : S) {
        occurrences[c - 'a'] += currentLength;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        std::string newS = f(S);
        currentLength *= 2;

        for (int i = 0; i < std::min(currentLength, r) - std::max(currentLength / 2, l) + 1; i++) {
            occurrences[c - 'a'] += (newS[i] == c) ? 1 : 0;
        }

        S = newS;
    }

    for (int i = 0; i < 26; i++) {
        std::cout << occurrences[i] << " ";
    }

    return 0;
}