#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

std::string getRoot(std::string word) {
    std::sort(word.begin(), word.end());
    word.erase(std::unique(word.begin(), word.end()), word.end());
    return word;
}

int main() {
    int n;
    std::cin >> n;

    std::unordered_set<std::string> unique_roots;
    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        unique_roots.insert(getRoot(word));
    }

    std::cout << unique_roots.size() << std::endl;

    return 0;
}