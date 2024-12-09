#include <iostream>

int main() {
    int n;
    while (std::cin >> n) {
        int count = 0;
        for (int a = 0; a <= 1000; a++) {
            for (int b = 0; b <= 1000; b++) {
                for (int c = 0; c <= 1000; c++) {
                    int d = n - a - b - c;
                    if (d >= 0 && d <= 1000) {
                        count++;
                    }
                }
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}