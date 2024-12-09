#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    for (int i = 0; i < q; i++) {
        int type, l, r, x, y;
        std::cin >> type >> l >> r;

        if (type == 1) {
            std::cin >> x >> y;
            for (int j = l - 1; j <= r - 1; j++) {
                std::string num_str = std::to_string(sequence[j]);
                for (char& digit : num_str) {
                    if (digit - '0' == x) {
                        digit = y + '0';
                    }
                }
                sequence[j] = std::stoi(num_str);
            }
        } else if (type == 2) {
            long long sum = 0;
            for (int j = l - 1; j <= r - 1; j++) {
                sum += sequence[j];
            }
            std::cout << sum << std::endl;
        }
    }

    return 0;
}