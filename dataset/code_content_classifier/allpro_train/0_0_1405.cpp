#include <iostream>
#include <string>
#include <algorithm>

bool isPossibleHash(const std::string& p, const std::string& h) {
    if (h.size() < p.size()) {
        return false;
    }

    size_t pos1 = h.find(p);
    if (pos1 == std::string::npos) {
        return false;
    }

    size_t pos2 = pos1 + p.size();
    std::string s1 = h.substr(0, pos1);
    std::string s2 = h.substr(pos2);

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    std::sort(p.begin(), p.end());

    return s1 + p + s2 == h;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        std::string p, h;
        std::cin >> p >> h;

        if (isPossibleHash(p, h)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}