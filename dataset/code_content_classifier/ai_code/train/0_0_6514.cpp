#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string a;
        std::cin >> a;

        std::sort(a.begin(), a.end());

        std::cout << a << std::endl;
    }

    return 0;
}