#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform d-sorting on a substring of a given string
std::string d_sort(std::string str, int k, int d) {
    std::string result = str;
    for (int i = 0; i <= str.length() - k; i++) {
        std::string sub = str.substr(i, k);
        std::vector<std::pair<char, int>> characters;
        for (int j = 0; j < sub.length(); j++) {
            characters.push_back({sub[j], j % d});
        }
        std::sort(characters.begin(), characters.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            } else {
                return a.first < b.first;
            }
        });
        for (int j = 0; j < sub.length(); j++) {
            result[i + j] = characters[j].first;
        }
    }
    return result;
}

int main() {
    std::string S;
    int m;

    std::cin >> S;
    std::cin >> m;

    for (int i = 0; i < m; i++) {
        int k, d;
        std::cin >> k >> d;

        S = d_sort(S, k, d);
        std::cout << S << std::endl;
    }

    return 0;
}
 
// Sample Input
// qwerty
// 3
// 4 2
// 6 3
// 5 2

// Sample Output
// qertwy
// qtewry
// qetyrw