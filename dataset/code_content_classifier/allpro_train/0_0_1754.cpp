#include <iostream>
#include <vector>

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

        int count = 0;
        int i = 0;
        while(i < n && a[i] > x) {
            i++;
        }
        if(i == n) {
            std::cout << -1 << std::endl;
            continue;
        }

        while(i < n) {
            if(a[i] > x) {
                std::swap(a[i], x);
                count++;
            }
            i++;
        }

        bool sorted = true;
        for(int i = 0; i < n-1; i++) {
            if(a[i] > a[i+1]) {
                sorted = false;
                break;
            }
        }

        if(sorted) {
            std::cout << count << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}