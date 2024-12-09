#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string a;
        std::cin >> a;

        int n = a.length();
        std::string b = a;

        // Sort the string in non-decreasing order
        std::sort(b.begin(), b.end());

        // If the sorted string is equal to the original string, swap the first two characters
        if (a == b) {
            std::swap(b[0], b[1]);
        }

        std::cout << b << std::endl;
    }

    return 0;
}