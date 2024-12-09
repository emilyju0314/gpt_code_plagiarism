#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    int count = 0;
    std::vector<int> positions;

    for (int i = 0; i <= m - n; i++) {
        bool found = true;
        for (int j = 0; j < n; j++) {
            if (s[j] != t[i + j] && s[j] != '?') {
                found = false;
                break;
            }
        }
        if (found) {
            for (int j = 0; j < n; j++) {
                if (s[j] != t[i + j]) {
                    count++;
                    positions.push_back(j + 1);
                }
            }
            break;
        }
    }

    std::cout << count << std::endl;
    for (int i = 0; i < positions.size(); i++) {
        std::cout << positions[i] << " ";
    }

    return 0;
}