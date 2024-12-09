#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    int count = 0;

    for (int b = 1; b <= n; b++) {
        for (int c = 1; c <= m; c++) {
            int discriminant = 4 * b * b - 4 * c;
            if (discriminant > 0) {
                count += 2;
            } else if (discriminant == 0) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}