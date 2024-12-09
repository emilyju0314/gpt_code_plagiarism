#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int a[4];
        for(int i = 0; i < 4; i++) {
            std::cin >> a[i];
        }
        
        std::sort(a, a+4);
        int maxArea = a[0] * a[2];
        std::cout << maxArea << std::endl;
    }

    return 0;
}