#include <iostream>
#include <vector>
#include <algorithm>

bool isSubstring(const std::string& a, const std::string& b) {
    return b.find(a) != std::string::npos;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> strings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }

    std::sort(strings.begin(), strings.end(), [](const std::string& a, const std::string& b) {
        return a.size() < b.size();
    });

    for (int i = 1; i < n; i++) {
        if (!isSubstring(strings[i-1], strings[i])) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;
    for (const std::string& s : strings) {
        std::cout << s << std::endl;
    }

    return 0;
}