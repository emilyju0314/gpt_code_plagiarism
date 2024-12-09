#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        for(int i = 0; i < n; i++) {
            std::cin >> b[i];
        }

        int maxA = *std::max_element(a.begin(), a.end());
        int maxB = *std::max_element(b.begin(), b.end());

        for(int i = 0; i < n; i++) {
            if(a[i] < maxA && b[i] < maxB) {
                std::cout << "0";
            } else {
                std::cout << "1";
            }
        }

        std::cout << std::endl;
    }

    return 0;
}