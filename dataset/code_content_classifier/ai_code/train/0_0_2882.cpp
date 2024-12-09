#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n, m, k;
    std::cin >> n;
    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::cin >> m;
    std::vector<int> y(m);
    for (int i = 0; i < m; i++) {
        std::cin >> y[i];
    }

    std::cin >> k;
    std::vector<int> z(k);
    for (int i = 0; i < k; i++) {
        std::cin >> z[i];
    }

    int A, B;
    std::cin >> A >> B;

    double max_r2 = 0;
    for (int xi : x) {
        for (int yi : y) {
            for (int zi : z) {
                double r2 = sqrt((A * zi * xi * xi) / (A * yi + B * zi));
                if (r2 > max_r2) {
                    max_r2 = r2;
                }
            }
        }
    }

    std::cout << max_r2 << std::endl;

    return 0;
}