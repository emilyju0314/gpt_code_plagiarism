#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> requirements(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> requirements[i];
    }

    std::vector<int> problems(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> problems[i];
    }

    int additional_problems = 0;
    std::sort(problems.begin(), problems.end());

    for (int i = 0; i < n; ++i) {
        if (std::binary_search(problems.begin(), problems.end(), requirements[i])) {
            continue;
        } else {
            ++additional_problems;
        }
    }

    std::cout << additional_problems << std::endl;

    return 0;
}