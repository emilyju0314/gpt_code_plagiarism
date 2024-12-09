#include <iostream>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    int min_k = 0, max_k = 0;
    int max_people = 0;

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        max_people = std::max(max_people, a);
        min_k += a;
    }

    min_k = std::max(max_people, (min_k + m + n - 1) / n);
    max_k = max_people + m;

    std::cout << min_k << " " << max_k << std::endl;

    return 0;
}