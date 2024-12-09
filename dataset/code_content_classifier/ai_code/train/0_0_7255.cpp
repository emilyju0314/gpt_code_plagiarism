#include <iostream>

bool canWin(int X, int Y) {
    if(X <= 1 && Y <= 1) {
        return false; // If both piles have less than or equal to 1 stone, current player loses
    }
    
    for(int i = 1; i <= X; i++) {
        if(!canWin(X - i, Y + i)) {
            return true; // If there is a way to force the opponent to lose, current player wins
        }
    }
    
    return false; // If no way to force the opponent to lose, current player loses
}

int main() {
    int X, Y;
    std::cin >> X >> Y;
    
    if(canWin(X, Y)) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Brown\n";
    }
    
    return 0;
}