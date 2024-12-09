#include <iostream>
#include <iomanip>

int main() {
    int m, n;
    std::cin >> m >> n;

    double ans = 0.0;
    for(int i = 1; i <= m; i++) {
        double p = 1.0;
        for(int j = 0; j < n; j++) {
            p *= (double)(i) / m;
        }
        ans += (double)(i) * (p - (double)(i - 1) / m);
    }

    std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
    
    return 0;
}