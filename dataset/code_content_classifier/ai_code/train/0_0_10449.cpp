#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<int, int>> positions;
    std::vector<char> characters;

    for(int i = 0; i < m; i++) {
        int l, r;
        char c;
        std::cin >> l >> r >> c;
        positions.push_back(std::make_pair(l, r));
        characters.push_back(c);
    }

    for(int i = 0; i < m; i++) {
        int l = positions[i].first;
        int r = positions[i].second;
        char c = characters[i];

        for(int j = l-1; j <= r-1; j++) {
            if(s[j] == c) {
                s[j] = '.';
            }
        }
    }

    std::string result;
    for(int i = 0; i < n; i++) {
        if(s[i] != '.') {
            result += s[i];
        }
    }

    std::cout << result << std::endl;

    return 0;
}