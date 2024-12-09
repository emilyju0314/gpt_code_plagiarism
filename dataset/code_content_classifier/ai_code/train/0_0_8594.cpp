#include <iostream>
#include <vector>
#include <algorithm>

bool check_symmetric_array(std::vector<long long>& d, int n) {
    std::sort(d.begin(), d.end());

    for (int i = 0; i < 2*n; i += 2) {
        if (d[i] != d[i+1] || d[i] % 2 != 0) {
            return false;
        }
    }
    
    long long diff = d[1] - d[0];
    for (int i = 2; i < 2*n; i += 2) {
        if (d[i] - d[i-1] != diff) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<long long> d(2*n);
        for (int i = 0; i < 2*n; i++) {
            std::cin >> d[i];
        }

        if (check_symmetric_array(d, n)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}