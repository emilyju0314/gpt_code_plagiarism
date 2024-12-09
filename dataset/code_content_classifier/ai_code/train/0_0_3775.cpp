#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int remaining_coupons = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 1) {
            if(remaining_coupons > 0) {
                remaining_coupons--;
            }
            else {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
        remaining_coupons += (a[i] / 2);
    }

    std::cout << "YES" << std::endl;

    return 0;
}