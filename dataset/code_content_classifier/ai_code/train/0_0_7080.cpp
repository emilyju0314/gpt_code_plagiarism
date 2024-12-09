#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    // Check if it is possible to change S into `AKIHABARA`
    std::string target = "AKIHABARA";
    bool possible = true;
    int targetIdx = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == target[targetIdx]) {
            targetIdx++;
        } else if (S[i] != 'A') {
            possible = false;
            break;
        }
    }

    if (targetIdx != target.length()) {
        possible = false;
    }

    if (possible) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}