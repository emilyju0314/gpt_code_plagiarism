#include <iostream>
#include <string>

int shortestStringAfterBombing(std::string s) {
    int n = s.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A' && s[i+1] == 'B') {
            count++;
            i++;
        } else if (s[i] == 'B' && s[i+1] == 'B') {
            count++;
            i++;
        }
    }

    return n - 2 * count;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        std::cout << shortestStringAfterBombing(s) << std::endl;
    }

    return 0;
}