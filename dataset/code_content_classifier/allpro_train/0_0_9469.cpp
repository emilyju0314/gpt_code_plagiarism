#include <iostream>
#include <string>
#include <algorithm>

int minChanges(std::string s, std::string u) {
    int minChanges = u.length();
    for (int i = 0; i <= s.length() - u.length(); i++) {
        int changes = 0;
        for (int j = 0; j < u.length(); j++) {
            if (s[i + j] != u[j]) {
                changes++;
            }
        }
        minChanges = std::min(minChanges, changes);
    }
    return minChanges;
}

int main() {
    std::string s, u;
    std::cin >> s >> u;

    int result = minChanges(s, u);
    std::cout << result << std::endl;

    return 0;
}