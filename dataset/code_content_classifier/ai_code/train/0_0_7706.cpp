#include <iostream>
#include <string>

char mysteriousDevice(char first, char second) {
    if (first == 'T' && second == 'T') {
        return 'T';
    } else if (first == 'T' && second == 'F') {
        return 'F';
    } else if (first == 'F' && second == 'T') {
        return 'T';
    } else {
        return 'T';
    }
}

int main() {
    int N;
    std::cin >> N;

    char lastAnimal;
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            char first, second;
            std::cin >> first >> second;
            lastAnimal = mysteriousDevice(first, second);
        } else {
            char nextAnimal;
            std::cin >> nextAnimal;
            lastAnimal = mysteriousDevice(lastAnimal, nextAnimal);
        }
    }

    std::cout << lastAnimal << std::endl;

    return 0;
}