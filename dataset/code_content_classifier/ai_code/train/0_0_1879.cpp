#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> couples(2 * n);
    for(int i = 0; i < 2 * n; i++) {
        std::cin >> couples[i];
    }

    int swaps = 0;
    for(int i = 0; i < 2 * n; i += 2) {
        int partner = couples[i];
        for(int j = i + 1; j < 2 * n; j++) {
            if(couples[j] == partner) {
                while(j > i + 1) {
                    std::swap(couples[j], couples[j - 1]);
                    j--;
                    swaps++;
                }
                break;
            }
        }
    }

    std::cout << swaps << std::endl;

    return 0;
}