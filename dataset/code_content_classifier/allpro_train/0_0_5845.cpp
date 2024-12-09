#include <iostream>
#include <vector>
#include <algorithm>

int calculateErrors(const std::string& code1, const std::string& code2) {
    int errors = 0;
    for (int i = 0; i < 6; i++) {
        if (code1[i] != code2[i]) {
            errors++;
        }
    }
    return errors;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> codes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> codes[i];
    }

    int maxK = 6;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int errors = calculateErrors(codes[i], codes[j]);
            maxK = std::min(maxK, errors);
        }
    }

    std::cout << maxK << std::endl;

    return 0;
}