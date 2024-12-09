#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int countZero = 0;
    int countOne = 0;
    for (char c : s) {
        if (c == '0') {
            countZero++;
        } else {
            countOne++;
        }
    }

    int minRemain = std::min(countZero, countOne);

    std::cout << n - minRemain * 2 << std::endl;

    return 0;
}