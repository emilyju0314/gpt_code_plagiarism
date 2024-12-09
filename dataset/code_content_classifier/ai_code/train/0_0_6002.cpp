#include <iostream>
#include <cmath>

int main() {
    int r, c;
    int moves = 0;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            int num;
            std::cin >> num;

            if(num == 1) {
                r = i;
                c = j;
            }
        }
    }

    int r_moves = abs(r - 2);
    int c_moves = abs(c - 2);

    moves = r_moves + c_moves;

    std::cout << moves << std::endl;

    return 0;
}