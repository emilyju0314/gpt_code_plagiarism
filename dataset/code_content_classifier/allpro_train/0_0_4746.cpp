#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string S, T;
    std::cin >> S;
    std::cin >> T;

    int q;
    std::cin >> q;

    std::vector<int> a(q), b(q), c(q), d(q);

    for (int i = 0; i < q; i++) {
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    for (int i = 0; i < q; i++) {
        std::string substring_S = S.substr(a[i] - 1, b[i] - a[i] + 1);
        std::string substring_T = T.substr(c[i] - 1, d[i] - c[i] + 1);

        // Check if both substrings contain only 'A' or 'B'
        if (substring_S.find('A') != std::string::npos && substring_S.find('B') != std::string::npos) {
            std::cout << "NO" << std::endl;
        } else if (substring_T.find('A') != std::string::npos && substring_T.find('B') != std::string::npos) {
            std::cout << "NO" << std::endl;
        } else {
            // Check if both substrings have the same number of 'A's and 'B's
            int count_A_S = std::count(substring_S.begin(), substring_S.end(), 'A');
            int count_B_S = std::count(substring_S.begin(), substring_S.end(), 'B');

            int count_A_T = std::count(substring_T.begin(), substring_T.end(), 'A');
            int count_B_T = std::count(substring_T.begin(), substring_T.end(), 'B');

            if (count_A_S == count_A_T && count_B_S == count_B_T) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}