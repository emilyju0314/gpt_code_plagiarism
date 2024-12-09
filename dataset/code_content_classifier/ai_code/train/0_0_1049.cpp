#include <iostream>
#include <vector>

int main() {
    int b, k;
    std::cin >> b >> k;

    std::vector<int> a(k);
    for (int i = 0; i < k; i++) {
        std::cin >> a[i];
    }

    int n = 0;
    for (int i = 0; i < k; i++) {
        n = n * b + a[i];
    }

    if (n % 2 == 0) {
        std::cout << "even" << std::endl;
    } else {
        std::cout << "odd" << std::endl;
    }

    return 0;
}