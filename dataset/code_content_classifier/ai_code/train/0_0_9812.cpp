#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int swaps = 0;
    for(int i = 0; i < n/2; i++) {
        swaps += std::abs(s[i] - s[n-1-i]);
    }

    std::cout << swaps << std::endl;

    return 0;
}