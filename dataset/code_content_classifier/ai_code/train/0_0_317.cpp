#include <iostream>
#include <string>

int main() {
    std::string cubes;
    std::cin >> cubes;

    int red = 0, blue = 0;
    for(char c : cubes) {
        if(c == '0') {
            red++;
        } else {
            blue++;
        }
    }

    std::cout << 2 * std::min(red, blue) << std::endl;

    return 0;
}