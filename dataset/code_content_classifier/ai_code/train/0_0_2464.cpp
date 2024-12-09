#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> correct(n);
    for (int i = 0; i < n; i++) {
        std::cin >> correct[i];
    }

    std::vector<int> wrong(m);
    for (int i = 0; i < m; i++) {
        std::cin >> wrong[i];
    }

    int minCorrect = *min_element(correct.begin(), correct.end());
    int minWrong = *min_element(wrong.begin(), wrong.end());

    int v = std::max(2 * minCorrect, minCorrect + 1);

    if (v < minWrong) {
        std::cout << v << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}