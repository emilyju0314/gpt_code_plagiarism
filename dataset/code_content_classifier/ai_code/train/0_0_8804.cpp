#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

bool containsSubstring(const std::string& word, const std::string& substring) {
    return (word.find(substring) != std::string::npos);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> forbidden(n);
    for (int i = 0; i < n; i++) {
        std::cin >> forbidden[i];
    }

    std::string w;
    std::cin >> w;

    char letter;
    std::cin >> letter;

    std::transform(w.begin(), w.end(), w.begin(), ::tolower);

    for (const auto& s : forbidden) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        size_t pos = 0;
        while ((pos = w.find(s, pos)) != std::string::npos) {
            for (size_t i = pos; i < pos + s.size(); i++) {
                w[i] = letter;
            }
            pos += s.size();
        }
    }

    std::cout << w << std::endl;

    return 0;
}