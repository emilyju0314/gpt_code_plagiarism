#include <iostream>
#include <vector>

int main() {
    std::string row1, row2;
    std::cin >> row1 >> row2;

    int n = row1.length();
    int bishwocks = 0;

    for (int i = 0; i < n; i++) {
        if (row1[i] == '0' && row2[i] == '0') {
            bishwocks++;
            i++;
        }
    }

    std::cout << bishwocks << std::endl;

    return 0;
}