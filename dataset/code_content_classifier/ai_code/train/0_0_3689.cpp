#include <iostream>

int main() {
    char seat;
    long long row;
    std::cin >> row >> seat;

    int position = (seat == 'a' || seat == 'b' || seat == 'c') ? 2 : (seat == 'd' || seat == 'e' || seat == 'f') ? 1 : 0;
    long long interval = (row % 2 == 1) ? (row / 2) * 6 + position : ((row - 1) / 2) * 6 + 3 + position;

    std::cout << interval << std::endl;

    return 0;
}