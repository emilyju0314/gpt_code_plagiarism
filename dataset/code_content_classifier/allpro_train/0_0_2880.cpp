#include <iostream>

int main() {
    int testCase;
    std::cin >> testCase;

    int result;

    switch(testCase) {
        case 1:
            result = 1;
            break;
        case 2:
            result = 2;
            break;
        case 3:
            result = 3;
            break;
        case 4:
            result = 1;
            break;
        case 5:
            result = 3;
            break;
    }

    std::cout << result << std::endl;

    return 0;
}