#include <iostream>
#include <string>

int main() {
    int n, t;
    std::cin >> n >> t;

    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::string result = s1;
    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (diff < t && s1[i] == s2[i]) {
            result[i] = (result[i] - 'a' + 1) % 26 + 'a';
            diff++;
        }
        if (diff == t) break;
    }

    if (diff == t) {
        std::cout << result << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}