#include <iostream>
#include <string>

int main() {
    std::string number;
    std::cin >> number;

    int count = 1;
    for (int i = 0; i < number.length() - 1; i++) {
        if ((number[i] - '0') + (number[i + 1] - '0') == 9) {
            int j = i + 2;
            while (j < number.length() && (number[j] - '0') + (number[j - 1] - '0') == 9) {
                j++;
            }
            count++;
            i = j - 1;
        }
    }

    std::cout << count << std::endl;

    return 0;
}