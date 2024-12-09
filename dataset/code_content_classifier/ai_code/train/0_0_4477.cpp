#include <iostream>
#include <string>

int main() {
    int N;
    std::string stones;
    std::cin >> N >> stones;

    int count = 0;
    int whiteBeforeRed = 0;

    for (int i = 0; i < N; i++) {
        if (stones[i] == 'W' && i % 2 == 0) {
            count++;
        } else if (stones[i] == 'R' && i % 2 == 1) {
            count++;
        }
        
        if (stones[i] == 'W' && i % 2 == 1) {
            whiteBeforeRed++;
        }
    }

    int operations = std::min(whiteBeforeRed, N - whiteBeforeRed) / 2;
    count += operations * 2;

    std::cout << count << std::endl;

    return 0;
}