#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> ans(n + 1, 0);

    for(int i = 0; i < n; i++) {
        std::vector<int> count(n + 1, 0);

        for(int j = i; j < n; j++) {
            int prod = 1;
            for(int k = i; k <= j; k++) {
                prod *= arr[k];
            }

            int root = sqrt(abs(prod));
            if(root * root == abs(prod)) {
                count[root]++;
            }
        }

        for(int k = 1; k <= n; k++) {
            ans[k] += count[k];
        }
    }

    for(int i = 1; i <= n; i++) {
        std::cout << ans[i] << " ";
    }

    return 0;
}