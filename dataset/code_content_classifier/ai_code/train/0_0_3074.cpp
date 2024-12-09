#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string cards;
    std::cin >> cards;

    std::vector<int> count(3, 0);
    for(char& c : cards) {
        if(c == 'R') {
            count[0]++;
        } else if(c == 'G') {
            count[1]++;
        } else {
            count[2]++;
        }
    }

    while(count[0] > 1) {
        count[0]--;
    }
    while(count[1] > 1) {
        count[1]--;
    }
    while(count[2] > 1) {
        count[2]--;
    }

    for(int i = 0; i < 3; i++) {
        if(count[i] == 1) {
            if(i == 0) {
                std::cout << "R";
            } else if(i == 1) {
                std::cout << "G";
            } else {
                std::cout << "B";
            }
        }
    }

    return 0;
}