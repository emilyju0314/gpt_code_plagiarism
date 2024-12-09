#include <iostream>
#include <string>

int main() {
    std::string actions1, actions2;
    
    // Input actions of both teams
    std::getline(std::cin, actions1);
    std::getline(std::cin, actions2);
    
    int score1 = 0, score2 = 0;

    // Calculate the score for each team based on their actions
    for (int i = 0; i < actions1.length(); i++) {
        if (actions1[i] == '8' && actions2[i] == '[') {
            score1++;
        } else if (actions1[i] == '(' && actions2[i] == '8') {
            score1++;
        } else if (actions1[i] == '[' && actions2[i] == '(') {
            score1++;
        } else if (actions1[i] == actions2[i]) {
            continue;
        } else {
            score2++;
        }
    }

    // Output the result
    if (score1 > score2) {
        std::cout << "TEAM 1 WINS" << std::endl;
    } else if (score2 > score1) {
        std::cout << "TEAM 2 WINS" << std::endl;
    } else {
        std::cout << "TIE" << std::endl;
    }

    return 0;
}