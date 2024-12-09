#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, x;
        std::cin >> n >> x;

        std::vector<int> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        int v = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == v + 1) {
                v = a[i];
            }
        }

        int add = 0;
        if(v < 100) {
            add = std::min(x, 100 - v);
        }

        std::cout << v + add << std::endl;
    }

    return 0;
}