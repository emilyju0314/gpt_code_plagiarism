#include <iostream>
#include <algorithm>

int main() {
    std::string S;
    std::cin >> S;

    // Sort the string to check if it can be obtained by permuting "abc"
    std::sort(S.begin(), S.end());

    if (S == "abc") {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}