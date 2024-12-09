#include <iostream>
#include <string>

char getCharacter(char button, int count) {
    switch(button) {
        case '1':
            return ".,!? "[count % 5];
        case '2':
            return 'a' + (count % 3);
        case '3':
            return 'd' + (count % 3);
        case '4':
            return 'g' + (count % 3);
        case '5':
            return 'j' + (count % 3);
        case '6':
            return 'm' + (count % 3);
        case '7':
            return 'p' + (count % 4);
        case '8':
            return 't' + (count % 3);
        case '9':
            return 'w' + (count % 3);
        default:
            return '\0';
    }
}

int main() {
    int testCases;
    std::cin >> testCases;

    while(testCases--) {
        std::string input;
        std::cin >> input;

        char prevButton = '\0';
        int count = 0;

        for(char button : input) {
            if(button == '0') {
                if(prevButton != '\0') {
                    std::cout << prevButton;
                }
                prevButton = '\0';
                count = 0;
            } else if(button == prevButton) {
                count++;
            } else {
                if(prevButton != '\0') {
                    std::cout << prevButton;
                }
                prevButton = button;
                count = 1;
            }
        }

        if(prevButton != '\0') {
            std::cout << prevButton;
        }
        std::cout << std::endl;
    }

    return 0;
}