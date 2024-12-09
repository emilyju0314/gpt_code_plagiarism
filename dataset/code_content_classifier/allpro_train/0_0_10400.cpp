#include <iostream>
#include <vector>
#include <string>

int main() {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        std::vector<std::string> result;
        std::string current = "";
        current += s[0];
        for (int j = 1; j < n; j++) {
            if (s[j] > s[j - 1]) {
                current += s[j];
            } else {
                result.push_back(current);
                current = "";
                current += s[j];
            }
        }
        if (!current.empty()) {
            result.push_back(current);
        }

        if (result.size() > 1) {
            std::cout << "YES\n" << result.size() << std::endl;
            for (const auto &part : result) {
                std::cout << part << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}