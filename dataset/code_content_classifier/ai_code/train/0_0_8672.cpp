#include <iostream>
#include <vector>
#include <cmath>

std::string canAchieveArray(std::vector<long long>& a, int n, int k) {
    for(int i = 0; i < n; i++) {
        if(a[i] % (k - 1) != 0) {
            return "NO";
        }

        long long num = a[i] / (k - 1);
        while(num > 0 && num % k == 0) {
            num /= k;
        }

        if(num != 1) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    int T;
    std::cin >> T;

    while(T--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::string result = canAchieveArray(a, n, k);
        std::cout << result << std::endl;
    }

    return 0;
}