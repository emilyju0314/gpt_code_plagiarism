#include <iostream>
#include <vector>

int main() {
    int x, y, x0, y0;
    std::cin >> x >> y >> x0 >> y0;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<bool>> visited(x, std::vector<bool>(y, false));
    visited[x0-1][y0-1] = true;

    int up = x0-1, down = x0-1, left = y0-1, right = y0-1;
    int total_tests = 1;

    std::vector<int> count(s.length()+1, 0);

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'U') {
            if (up > 0) up--;
        } else if (s[i] == 'D') {
            if (down < x-1) down++;
        } else if (s[i] == 'L') {
            if (left > 0) left--;
        } else {
            if (right < y-1) right++;
        }
        if (!visited[up][left] && !visited[up][right] && !visited[down][left] && !visited[down][right]) {
            total_tests++;
        }
        visited[up][left] = true;
        count[total_tests]++;
    }

    for (int i = 0; i <= s.length(); i++) {
        std::cout << count[i] << " ";
    }

    return 0;
}