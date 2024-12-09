#include <iostream>
#include <iomanip>

int count_lucky_numbers(int x) {
    int count = 0;
    while (x > 0) {
        int digit = x % 10;
        if (digit == 4 || digit == 7) {
            count++;
        }
        x /= 10;
    }
    return count;
}

int main() {
    int pl, pr, vl, vr, k;
    std::cin >> pl >> pr >> vl >> vr >> k;

    long long total_pairs = (pr - pl + 1) * (vr - vl + 1);
    long long lucky_pairs = 0;

    for (int p = pl; p <= pr; p++) {
        for (int v = vl; v <= vr; v++) {
            int min_val = std::min(p, v);
            int max_val = std::max(p, v);
            int count = count_lucky_numbers(min_val);
            count += count_lucky_numbers(max_val);

            if (count == k) {
                lucky_pairs++;
            }
        }
    }

    double probability = (double) lucky_pairs / total_pairs;
    std::cout << std::fixed << std::setprecision(12) << probability << std::endl;

    return 0;
}