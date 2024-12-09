#include <iostream>
#include <unordered_map>

int main() {
    int n;
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }

        std::unordered_map<char, char> conversion_table;
        for (int i = 0; i < n; ++i) {
            char before, after;
            std::cin >> before >> after;
            conversion_table[before] = after;
        }

        int m;
        std::cin >> m;

        for (int i = 0; i < m; ++i) {
            char c;
            std::cin >> c;
            if (conversion_table.find(c) != conversion_table.end()) {
                std::cout << conversion_table[c];
            } else {
                std::cout << c;
            }
        }

        std::cout << std::endl;
    }

    return 0;
}