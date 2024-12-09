#include <iostream>

int main() {
    int d, L, v1, v2;
    std::cin >> d >> L >> v1 >> v2;

    double time;
    if (v1 == v2) {
        time = (double)(L - d) / (double)v1;
    } else {
        time = (double)(L - d) / (double)(v1 + v2);
    }

    std::cout << std::fixed;
    std::cout.precision(10);
    std::cout << time << std::endl;

    return 0;
}