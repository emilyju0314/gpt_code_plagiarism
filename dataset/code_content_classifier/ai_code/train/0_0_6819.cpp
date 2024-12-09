#include <iostream>
#include <string>
#include <set>

int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    int max_diff_letters = 0;

    for (int i = 1; i < N; i++) {
        std::set<char> X, Y;

        for (int j = 0; j < i; j++) {
            X.insert(S[j]);
        }

        for (int j = i; j < N; j++) {
            Y.insert(S[j]);
        }

        int diff_letters = 0;
        for (char c : X) {
            if (Y.count(c)) {
                diff_letters++;
            }
        }

        if (diff_letters > max_diff_letters) {
            max_diff_letters = diff_letters;
        }
    }

    std::cout << max_diff_letters << std::endl;

    return 0;
}