#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int n = s.length();
    std::vector<int> prefix(n, 0);

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + (s[i - 1] == s[i] ? 1 : 0);
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; i++) {
        int li, ri;
        std::cin >> li >> ri;
        std::cout << prefix[ri - 1] - prefix[li - 1] << std::endl;
    }

    return 0;
}