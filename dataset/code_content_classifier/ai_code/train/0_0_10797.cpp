#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string x;
    std::cin >> x;

    int actions = 0;
    
    while (x != "1") {
        if (x[x.size() - 1] == '1') {
            x[x.size() - 1] = '0';
            actions++;
        } else {
            x = x.substr(0, x.size() - 1);
            actions++;
        }
        while (x.size() > 1 && x[x.size() - 1] == '0') {
            x = x.substr(0, x.size() - 1);
            actions++;
        }
    }

    std::cout << actions << std::endl;

    return 0;
}