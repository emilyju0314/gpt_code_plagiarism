#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());

    if (s <= t) {
        std::cout << -1 << std::endl;
    } else {
        for (char c : s) {
            if (c > t[0]) {
                std::cout << c;
                s.erase(s.find(c), 1);
                break;
            }
        }
        std::cout << s << std::endl;
    }

    return 0;
}