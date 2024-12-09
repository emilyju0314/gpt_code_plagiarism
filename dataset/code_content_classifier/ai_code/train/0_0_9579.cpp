#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    int m;
    std::cin >> m;

    std::unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[array[i]]++;
    }

    while (m--) {
        int l, r;
        std::cin >> l >> r;

        int result = 0;
        for (int i = l - 1; i < r; i++) {
            if (count[array[i]] % 2 == 0) {
                result ^= array[i];
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}