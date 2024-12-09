#include <iostream>

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int n, s, t;
        std::cin >> n >> s >> t;

        int min_eggs = std::max(s, t) - std::min(s, t) + 1;
        std::cout << std::max(min_eggs, n - std::max(s, t) + 1) << std::endl;
    }

    return 0;
}