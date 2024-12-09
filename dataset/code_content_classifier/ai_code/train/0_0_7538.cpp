#include <iostream>

int main() {
    int w1, h1, w2, h2;
    std::cin >> w1 >> h1 >> w2 >> h2;

    // Calculate the total cells in the first rectangle
    int total1 = 2 * (w1 + h1);

    // Calculate the total cells in the second rectangle
    int total2 = 2 * (w2 + h2);

    // Calculate the overlapping area
    int overlap = 2 * h2;

    // Calculate the number of cells to be marked after the ship is destroyed
    int marked = total1 + total2 - overlap + 4;

    std::cout << marked << std::endl;

    return 0;
}