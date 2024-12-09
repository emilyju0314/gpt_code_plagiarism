#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string s;
    std::cin >> s;

    int k;
    std::cin >> k;

    std::unordered_set<std::string> forbiddenPairs;
    for (int i = 0; i < k; ++i) {
        std::string pair;
        std::cin >> pair;
        forbiddenPairs.insert(pair);
    }

    int count = 0;
    std::string result = "";
    for (int i = 0; i < s.size(); ++i) {
        if (i < s.size() - 1 && forbiddenPairs.find(s.substr(i, 2)) != forbiddenPairs.end()) {
            count++;
            i++;
        } else {
            result += s[i];
        }
    }

    std::cout << count << std::endl;

    return 0;
}