#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n), b(n);
        int sum = 0;

        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            sum += a[i];
        }

        // Choose non-zero value for b[0] such that the total sum is 0
        b[0] = -sum;

        // Choose non-zero value for the rest of the elements
        for(int i = 1; i < n; i++) {
            b[i] = 1; // Choosing 1
        }

        // Output the array b
        for(int i = 0; i < n; i++) {
            std::cout << b[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}