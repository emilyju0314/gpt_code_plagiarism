#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string s;
    std::cin >> s;

    int x = 0, y = 0; // starting position
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'N') y++;
        else if(s[i] == 'S') y--;
        else if(s[i] == 'E') x++;
        else if(s[i] == 'W') x--;
    }

    if(x == 0 && y == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}