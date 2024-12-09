#include <iostream>
#include <string>

int main() {
    std::string x, y;
    std::cin >> x >> y;

    std::string z = x;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] > y[i]) {
            z[i] = y[i];
        }
        else if (x[i] < y[i]) {
            z[i] = y[i];
        } else {
            z[i] = x[i]; 
        }
    }

    if (z == y) {
        std::cout << z << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}