#include <iostream>
#include <string>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;

    double total = 0.0;
    for (int i = 0; i < N; i++) {
        double x;
        std::string u;
        std::cin >> x >> u;

        if (u == "JPY") {
            total += x;
        } else if (u == "BTC") {
            total += x * 380000.0;
        }
    }

    std::cout << std::fixed << std::setprecision(6) << total << std::endl;

    return 0;
}