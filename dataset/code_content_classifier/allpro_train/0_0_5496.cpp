#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> bills(n);
    for(int i = 0; i < n; i++) {
        std::cin >> bills[i];
    }

    int q;
    std::cin >> q;

    for(int i = 0; i < q; i++) {
        int x;
        std::cin >> x;

        int min_bills = INT_MAX;
        for(int mask = 0; mask < (1 << n); mask++) {
            int sum = 0, count = 0;
            for(int j = 0; j < n; j++) {
                if((mask & (1 << j)) != 0) {
                    sum += bills[j];
                    count++;
                }
            }

            if(sum == x) {
                min_bills = std::min(min_bills, count);
            }
        }

        if(min_bills != INT_MAX && min_bills <= k) {
            std::cout << min_bills << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}