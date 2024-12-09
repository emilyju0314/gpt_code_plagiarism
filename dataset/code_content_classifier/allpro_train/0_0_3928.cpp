#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::stack<int> leftStones, rightStones;

    int stoneNumber = 1;
    for (char c : s) {
        if (c == 'l') {
            leftStones.push(stoneNumber);
        } else {
            rightStones.push(stoneNumber);
        }
        stoneNumber++;
    }

    while (!leftStones.empty()) {
        std::cout << leftStones.top() << std::endl;
        leftStones.pop();
    }

    while (!rightStones.empty()) {
        std::cout << rightStones.top() << std::endl;
        rightStones.pop();
    }

    return 0;
}