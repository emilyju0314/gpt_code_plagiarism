#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int sum = 0;

    // Input the rating changes and calculate the sum
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
    }

    // Modify the rating changes to satisfy the conditions
    std::vector<int> b(n);
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) {
            b[i] = a[i] / 2;
        } else {
            if(sum > 0) {
                b[i] = std::floor(a[i] / 2.0);
                sum -= 1;
            } else {
                b[i] = std::ceil(a[i] / 2.0);
                sum += 1;
            }
        }
    }

    // Output the modified rating changes
    for(int i = 0; i < n; i++) {
        std::cout << b[i] << std::endl;
    }

    return 0;
}