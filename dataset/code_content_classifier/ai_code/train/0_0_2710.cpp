#include <iostream>
#include <vector>

int main() {
    int n, b;
    std::cin >> n >> b;

    std::vector<int> mugs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> mugs[i];
    }

    int total_volume = b;
    for (int i = 0; i < n; ++i) {
        total_volume += mugs[i];
    }

    if (total_volume % n == 0) {
        int equal_volume = total_volume / n;
        for (int i = 0; i < n; ++i) {
            std::cout << equal_volume - mugs[i] << ".000000\n";
        }
    } else {
        std::cout << "-1\n";
    }

    return 0;
}