#include <iostream>
#include <cmath>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    int total = 2 * n; // total length of all sides of the frames for two doors
    int sides = 4; // number of sides for two doors (2 left + 2 right)

    // check if the vertical sides fit in the initial wooden bars
    if (a * sides <= n) {
        // check if the top side fits in the initial wooden bars
        if (b * 2 <= n) {
            std::cout << 1 << std::endl;
        } else {
            // if the top side doesn't fit, calculate how many more wooden bars are needed
            int extra = std::ceil(double(b * 2) / n);
            std::cout << extra << std::endl;
        }
    } else {
        // if the vertical sides don't fit, calculate how many more wooden bars are needed
        int extra = std::ceil(double(a * sides) / n);
        std::cout << extra << std::endl;
    }

    return 0;
}