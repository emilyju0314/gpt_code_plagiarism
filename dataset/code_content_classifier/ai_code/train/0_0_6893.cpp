#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> elements(n);
    for (int i = 0; i < n; i++) {
        std::cin >> elements[i];
    }

    bool mojtaba = true;
    for (int i = 0; i < n; i++) {
        if (!isPrime(elements[i])) {
            if (elements[i] % 2 == 0) {
                std::cout << "Arpa" << std::endl;
                return 0;
            } else {
                if (elements[i] == 1) {
                    std::cout << "Mojtaba" << std::endl;
                    return 0;
                } else {
                    mojtaba = !mojtaba;
                }
            }
        }
    }

    if (mojtaba) {
        std::cout << "Mojtaba" << std::endl;
    } else {
        std::cout << "Arpa" << std::endl;
    }

    return 0;
}