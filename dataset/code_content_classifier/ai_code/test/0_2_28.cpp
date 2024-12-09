#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        int total_duration = a + 2 * b + 3 * c;
        int min_difference = total_duration % 2 == 0 ? 0 : 1;
        
        std::cout << min_difference << std::endl;
    }

    return 0;
}