#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int total_open = 0;
    int total_closed = 0;
    int max_rbs = 0;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        int open = std::count(s.begin(), s.end(), '(');
        int closed = s.size() - open;

        total_open += open;
        total_closed += closed;

        int diff = total_open - total_closed;
        if (diff >= 0) {
            max_rbs = std::max(max_rbs, 2 * std::min(total_open, total_closed));
        }
    }

    std::cout << max_rbs << std::endl;

    return 0;
}