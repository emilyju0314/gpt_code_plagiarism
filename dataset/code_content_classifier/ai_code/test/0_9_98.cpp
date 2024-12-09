#include <iostream>
#include <cmath>
#include <string>

int findTime(std::string keyboard, std::string word) {
    int time = 0;
    int prevPos = 0;
    
    for(char c : word) {
        time += abs(keyboard.find(c) - prevPos);
        prevPos = keyboard.find(c);
    }
    
    return time;
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        std::string keyboard, word;
        std::cin >> keyboard >> word;

        std::cout << findTime(keyboard, word) << std::endl;
    }

    return 0;
}