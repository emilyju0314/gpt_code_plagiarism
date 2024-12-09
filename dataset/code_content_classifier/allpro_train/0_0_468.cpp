#include <iostream>
#include <vector>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    for (int i = 0; i < n; i++) {
        int ai;
        std::cin >> ai;

        long long time_vanya = (ai * x - 1) / y;
        long long time_vova = (ai * y - 1) / x;

        if (time_vanya > time_vova) {
            std::cout << "Vova" << std::endl;
        } else if (time_vanya < time_vova) {
            std::cout << "Vanya" << std::endl;
        } else {
            std::cout << "Both" << std::endl;
        }
    }

    return 0;
}