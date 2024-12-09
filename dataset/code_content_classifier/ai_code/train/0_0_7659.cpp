#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> names(n);
    std::vector<std::string> surnames(n);

    for (int i = 0; i < n; i++) {
        std::cin >> names[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> surnames[i];
    }

    std::sort(names.begin(), names.end());
    std::sort(surnames.begin(), surnames.end());

    for (int i = 0; i < n; i++) {
        std::cout << names[i] << " " << surnames[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }

    return 0;
}