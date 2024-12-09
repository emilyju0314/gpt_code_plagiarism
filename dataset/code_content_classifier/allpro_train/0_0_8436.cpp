#include <iostream>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;

    int firstPlayerWins = 0, draw = 0, secondPlayerWins = 0;

    for(int i = 1; i <= 6; i++) {
        int distA = abs(a - i);
        int distB = abs(b - i);

        if(distA < distB) {
            firstPlayerWins++;
        } else if(distA == distB) {
            draw++;
        } else {
            secondPlayerWins++;
        }
    }

    std::cout << firstPlayerWins << " " << draw << " " << secondPlayerWins << std::endl;

    return 0;
}