#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t; // Number of test cases

    while (t--) {
        int n;
        std::cin >> n; // Length of array a
        std::vector<int> a(n);

        for (int i = 0; i < n; i++) {
            std::cin >> a[i]; // Input array a
        }

        std::vector<int> possible_values; // Store possible values of k

        for (int k = 1; k <= n; k++) {
            bool possible = true;
            int x = a[0]; // Initialize x with first element of array a

            for (int i = 1; i < n; i++) {
                x = x & a[i]; // Perform bitwise AND operation
            }

            if ((x & (1 << k)) == 0) {
                for (int i = 0; i < n; i++) {
                    if ((a[i] & (1 << k)) != 0) {
                        possible = false;
                        break;
                    }
                }
            } else {
                possible = false;
            }

            if (possible) {
                possible_values.push_back(k);
            }
        }

        for (int val : possible_values) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}