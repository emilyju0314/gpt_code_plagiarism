#include <iostream>
#include <string>

int main() {
    int n;
    std::string outcome;
    std::cin >> n >> outcome;

    int antonWins = 0, danikWins = 0;

    for(int i = 0; i < n; i++) {
        if(outcome[i] == 'A') {
            antonWins++;
        } else {
            danikWins++;
        }
    }

    if(antonWins > danikWins) {
        std::cout << "Anton";
    } else if(danikWins > antonWins) {
        std::cout << "Danik";
    } else {
        std::cout << "Friendship";
    }

    return 0;
}