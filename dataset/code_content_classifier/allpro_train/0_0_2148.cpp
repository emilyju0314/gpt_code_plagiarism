#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int count = 0;
    for (int month = 1; month <= a; month++) {
        for (int day = 1; day <= b; day++) {
            if (month == day) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}