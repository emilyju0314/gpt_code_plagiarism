#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a, a+n);

    for(int i = 0; i < n-2; i++) {
        if(a[i] + a[i+1] > a[i+2]) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;

    return 0;
}