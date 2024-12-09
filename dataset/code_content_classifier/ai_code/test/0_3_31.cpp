#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        std::vector<int> b(n);

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
            sum += arr[i];
        }

        for (int i = 0; i < n-1; ++i) {
            b[i] = 1;
            sum -= arr[i];
        }
        b[n-1] = -sum;

        for (int i = 0; i < n; ++i) {
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}