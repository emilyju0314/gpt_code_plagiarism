#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int knights = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(knights < n) {
                std::cout << i << " " << j << "\n";
                knights++;
            }
        }
    }

    return 0;
}