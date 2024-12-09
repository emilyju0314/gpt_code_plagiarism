#include <iostream>
#include <string>

int main() {
    std::string n;
    std::cin >> n;
    
    for (int i = 0; i < 3; i++) {
        if (n[i] == '1') {
            n[i] = '9';
        } else if (n[i] == '9') {
            n[i] = '1';
        }
    }

    std::cout << n << std::endl;

    return 0;
}