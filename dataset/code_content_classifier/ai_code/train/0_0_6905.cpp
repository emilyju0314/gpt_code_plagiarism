#include <iostream>
#include <cmath>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    for (int i = 0; i < Q; i++) {
        int v, w;
        std::cin >> v >> w;

        while (v != w) {
            if (v > w) {
                v = ceil((double)v / N);
            } else {
                w = ceil((double)w / N);
            }
        }

        std::cout << v << std::endl;
    }

    return 0;
}