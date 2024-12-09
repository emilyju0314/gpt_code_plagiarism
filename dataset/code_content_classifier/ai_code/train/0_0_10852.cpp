#include <iostream>

int main() {
    int n, d, m, l;
    std::cin >> n >> d >> m >> l;

    long long pos = 0;
    long long jump = d;

    for (int i = 1; i <= n; i++) {
        long long start = (i - 1) * m;
        long long end = start + l;

        if (pos >= start && pos < end) {
            pos += jump;
        } else {
            long long closest_edge = std::min(std::abs(pos - start), std::abs(pos - end));
            if (pos < start) {
                pos = start + closest_edge;
            } else {
                pos = end - closest_edge;
            }
            break;
        }
    }

    std::cout << pos << std::endl;

    return 0;
}