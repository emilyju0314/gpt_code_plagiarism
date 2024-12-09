#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    long long a = -1, b = -1;
    long long low = 1, high = n;

    // Binary search to find the values of a and b
    while (low <= high) {
        long long mid = (low + high) / 2;
        std::cout << mid << " " << mid << std::endl;
        std::cout.flush();

        int ans;
        std::cin >> ans;
        if (ans == 0) {
            break;
        } else if (ans == 1) {
            high = mid - 1;
        } else if (ans == 2) {
            low = mid + 1;
        } else {
            a = mid;
            break;
        }
    }

    low = 1;
    high = n;

    while (low <= high) {
        long long mid = (low + high) / 2;
        std::cout << a << " " << mid << std::endl;
        std::cout.flush();

        int ans;
        std::cin >> ans;
        if (ans == 0) {
            break;
        } else if (ans == 2) {
            high = mid - 1;
        } else if (ans == 1) {
            low = mid + 1;
        } else {
            b = mid;
            break;
        }
    }

    std::cout << a << " " << b << std::endl;
    std::cout.flush();

    return 0;
}