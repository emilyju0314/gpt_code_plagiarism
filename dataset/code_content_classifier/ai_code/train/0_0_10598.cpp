#include <iostream>

int main() {
    int n, m, x, y, a, b;
    std::cin >> n >> m >> x >> y >> a >> b;

    int dx = a / 2;
    int dy = b / 2;

    int x1, y1, x2, y2;
    x1 = std::max(0, x - dx);
    y1 = std::max(0, y - dy);

    x2 = std::min(n, x1 + a);
    y2 = std::min(m, y1 + b);

    if (x2 - x1 < a) {
        if (x1 == 0) {
            x2 = a;
        } else {
            x1 = n - a;
        }
    }

    if (y2 - y1 < b) {
        if (y1 == 0) {
            y2 = b;
        } else {
            y1 = m - b;
        }
    }

    std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;

    return 0;
}