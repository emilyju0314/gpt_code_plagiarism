#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> cream(n);
        for (int i = 0; i < n; i++) {
            std::cin >> cream[i];
        }

        std::vector<int> drenched(n, 0);
        int maxCream = 0;

        for (int i = n-1; i >= 0; i--) {
            maxCream = std::max(maxCream, cream[i]);
            if (maxCream > 0) {
                drenched[i] = 1;
            }
            maxCream = std::max(0, maxCream - 1);
        }

        for (int i = 0; i < n; i++) {
            std::cout << drenched[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}