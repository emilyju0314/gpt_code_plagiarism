#include <iostream>
#include <vector>

int main() {
    int n, w;
    std::cin >> n >> w;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::vector<int> score(n, 0);
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = std::max(0, i - w); j <= std::min(n - 1, i + w); ++j) {
            if (j == i || b[j] % 2 == 0) {
                count++;
            }
        }
        score[i] = count % 2 == 0 ? a[i] : b[i];
    }

    for (int i = 0; i < n; ++i) {
        std::cout << (score[i] % 2 == 0 ? 0 : 1);
    }
    std::cout << std::endl;

    return 0;
}