#include <iostream>

int main() {
    int n, x;
    std::cin >> n >> x;

    n = n % 6;
    int initial_position;

    if(n == 1) {
        if(x == 0) initial_position = 1;
        else if(x == 1) initial_position = 0;
        else initial_position = 2;
    } else if(n == 2) {
        if(x == 0) initial_position = 0;
        else if(x == 1) initial_position = 2;
        else initial_position = 1;
    } else if(n == 3) {
        if(x == 0) initial_position = 2;
        else if(x == 1) initial_position = 1;
        else initial_position = 0;
    } else if(n == 4) {
        if(x == 0) initial_position = 1;
        else if(x == 1) initial_position = 0;
        else initial_position = 2;
    } else if(n == 5) {
        if(x == 0) initial_position = 2;
        else if(x == 1) initial_position = 1;
        else initial_position = 0;
    } else {
        initial_position = x;
    }

    std::cout << initial_position << std::endl;

    return 0;
}