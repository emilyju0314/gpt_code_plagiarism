#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string input;
    std::cin >> input;

    std::string a = input.substr(0, input.find('+'));
    std::string b = input.substr(input.find('+') + 1, input.find('=') - input.find('+') - 1);
    std::string c = input.substr(input.find('=') + 1);

    int maxLen = std::max({a.length(), b.length(), c.length()});

    while (a.length() < maxLen) a = "0" + a;
    while (b.length() < maxLen) b = "0" + b;
    while (c.length() < maxLen) c = "0" + c;

    std::string x = "0";
    std::string y = "0";
    
    for (int i = 0; i < maxLen; i++) {
        if (a[i] + b[i] != c[i]) {
            x += std::to_string(a[i] - '0' + b[i] - '0');
            y += b[i];
        } else {
            x += a[i];
            y += b[i];
        }
    }

    std::cout << x << "+" << y << "=" << c << std::endl;

    return 0;
}