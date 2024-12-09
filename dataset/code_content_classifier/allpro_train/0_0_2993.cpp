#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> ink(n);
    for(int i = 0; i < n; i++) {
        std::cin >> ink[i];
    }

    int day = 0;
    int min_ink = ink[0];
    int result = 1;
    for(int i = 0; i < 7; i++) {
        if(ink[i % n] < min_ink) {
            min_ink = ink[i % n];
            result = i % n + 1;
        }
    }

    std::cout << result << std::endl;

    return 0;
}