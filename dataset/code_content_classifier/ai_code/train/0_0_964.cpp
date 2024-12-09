#include <iostream>

int main() {
    int x;
    std::cin >> x;

    int remainder = x % 4;
    int increase = 0;
    char category;

    if (remainder == 1) {
        category = 'A';
    } else if (remainder == 3) {
        category = 'B';
        increase = 2;
    } else if (remainder == 2) {
        category = 'C';
        increase = 1;
    } else {
        category = 'D';
        if (x % 4 == 0) {
            increase = 2;
        } else {
            increase = 1;
        }
    }

    std::cout << increase << " " << category;

    return 0;
}