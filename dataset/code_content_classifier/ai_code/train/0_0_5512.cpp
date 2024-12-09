#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    int n = input.size();

    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            std::string a = input.substr(0, i);
            std::string b = input.substr(i, j - i);
            std::string c = input.substr(j);

            if ((a[0] != '0' || a.size() == 1) && (b[0] != '0' || b.size() == 1) && (c[0] != '0' || c.size() == 1)) {
                if (std::stoll(a) + std::stoll(b) == std::stoll(c)) {
                    std::cout << a << "+" << b << "=" << c << std::endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}