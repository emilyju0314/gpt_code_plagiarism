#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, h;
    std::cin >> n >> h;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int min_goodness = a[n-1] + a[n-2] - a[0] - a[1];
    std::cout << min_goodness << std::endl;

    for(int i = 0; i < n; i++) {
        if(i < 2) {
            std::cout << "1 ";
        } else {
            std::cout << "2 ";
        }
    }

    return 0;
}