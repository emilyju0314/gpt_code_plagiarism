#include <iostream>
#include <algorithm>
#include <string>

int calculateIterations(int n) {
    int count = 0;
    while (n != 6174) {
        std::string str = std::to_string(n);
        while (str.length() < 4) {
            str = "0" + str;
        }
        std::sort(str.begin(), str.end(), std::greater<char>());
        int L = std::stoi(str);
        std::sort(str.begin(), str.end());
        int S = std::stoi(str);
        n = L - S;
        count++;
        if (n == 0) {
            return -1; // All digits are the same
        }
    }
    return count;
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        int result = calculateIterations(n);
        if (result == -1) {
            std::cout << "NA" << std::endl;
        } else {
            std::cout << result << std::endl;
        }
    }
    return 0;
}