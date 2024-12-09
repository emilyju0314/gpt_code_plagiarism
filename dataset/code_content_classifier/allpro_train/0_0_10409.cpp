#include <iostream>
#include <string>

int main() {
    std::string program;
    std::cin >> program;

    bool output = false;

    for(char c : program) {
        if(c == 'H' || c == 'Q' || c == '9') {
            output = true;
            break;
        }
    }

    if(output) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}