#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for(int i=0; i<t; i++) {
        int a, b, c, r;
        std::cin >> a >> b >> c >> r;

        // Calculate the left and right boundaries of the coverage area
        int left = c - r;
        int right = c + r;

        int unavailable_time = 0;

        // Check if the starting point is outside the coverage area
        if(a < left) {
            unavailable_time += std::max(0, left - a);
        }
        // Check if the ending point is outside the coverage area
        if(b > right) {
            unavailable_time += std::max(0, b - right);
        }

        std::cout << unavailable_time << std::endl;
    }

    return 0;
}