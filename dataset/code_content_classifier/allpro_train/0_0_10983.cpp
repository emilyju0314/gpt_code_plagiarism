#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cardValue;
    
    while (true) {
        vector<int> cards;
        
        // Read input
        while (cin >> cardValue && cardValue != 0) {
            cards.push_back(cardValue);
        }
        
        // Check for end of input
        if (cards.empty()) {
            break;
        }
        
        // Calculate hand score
        int score = 0;
        bool hasAce = false;
        for (int card : cards) {
            if (card == 1) {
                hasAce = true;
            }
            if (card >= 2 && card <= 9) {
                score += card;
            } else {
                score += 10;
            }
        }
        
        if (hasAce && score + 10 <= 21) {
            score += 10;
        }
        
        // Output hand score
        if (score > 21) {
            cout << "0" << endl;
        } else {
            cout << score << endl;
        }
    }
    
    return 0;
}