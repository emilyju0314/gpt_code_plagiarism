#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int bills[] = {100, 20, 10, 5, 1};
    int numBills = 0;

    for(int i = 0; i < 5; i++) {
        numBills += n / bills[i];
        n %= bills[i];
    }

    std::cout << numBills << std::endl;

    return 0;
}