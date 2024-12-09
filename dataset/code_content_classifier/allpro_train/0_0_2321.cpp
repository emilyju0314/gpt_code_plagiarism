#include <iostream>
#include <iomanip>

int main() {
    long long n, m, d;
    std::cin >> n >> m >> d;

    double total_pairs = 0;
    double total_sequences = 1;
    for (int i = 0; i < m; i++) {
        total_pairs += (m - i - 1) * (n - d) * (n - d);
        total_sequences *= n;
    }

    double average_beauty = total_pairs / total_sequences;
    std::cout << std::fixed << std::setprecision(10) << average_beauty << std::endl;

    return 0;
}