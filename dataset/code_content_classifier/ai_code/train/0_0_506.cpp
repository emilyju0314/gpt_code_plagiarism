#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Card {
    char suit;
    char rank;
};

int getTime(char action) {
    if (action == 'D') {
        return 300;
    } else if (action == 'R') {
        return 500;
    } else if (action == 'L') {
        return 700;
    } else { // Return action is a constant time of 500ms for returning a card to its original position
        return 500;
    }
}

bool compareRanks(char rank1, char rank2) {
    string ranks = "KAQJX98765432";
    return ranks.find(rank1) > ranks.find(rank2);
}

bool compareSuits(char suit1, char suit2) {
    string suits = "SHDC";
    return suits.find(suit1) > suits.find(suit2);
}

bool isValidMove(Card topCard, Card movedCard) {
    if (abs(topCard.rank - movedCard.rank) == 1 || (topCard.rank == 'A' && movedCard.rank == 'K') || (topCard.rank == 'K' && movedCard.rank == 'A')) {
        return true;
    }
    return false;
}

void playGame(vector<Card>& deckA, vector<Card>& deckB) {
    vector<Card> tableauA, tableauB;
    vector<Card> tableA, tableB;
    Card topCardA, topCardB;
    int time = 0;
    
    while (!deckA.empty() || !deckB.empty()) {
        if (!deckA.empty()) {
            tableauA.push_back(deckA.back());
            deckA.pop_back();
        }
        if (!deckB.empty()) {
            tableauB.push_back(deckB.back());
            deckB.pop_back();
        }
    }
    
    topCardA = tableauA.back();
    tableauA.pop_back();
    topCardB = tableauB.back();
    tableauB.pop_back();
    
    while (true) {
        char actionA = 'D', actionB = 'D';
        
        if (!tableauA.empty()) {
            tableA.push_back(topCardA);
            actionA = 'R';
            topCardA = tableauA.back();
            tableauA.pop_back();
        }
        if (!tableauB.empty()) {
            tableB.push_back(topCardB);
            actionB = 'R';
            topCardB = tableauB.back();
            tableauB.pop_back();
        }
        
        // Perform actions
        int timeA = getTime(actionA);
        int timeB = getTime(actionB);
        
        if (timeA < timeB) {
            time += timeA;
        } else {
            time += timeB;
        }
        
        // Check if the game needs to continue or someone has run out of cards
        if (tableauA.empty() && deckA.empty()) {
            cout << "B wins." << endl;
            break;
        } else if (tableauB.empty() && deckB.empty()) {
            cout << "A wins." << endl;
            break;
        }
    }
}

int main() {
    vector<Card> deckA, deckB;
    string input;
    
    while (true) {
        int NA, NB;
        cin >> NA;
        if (NA == 0) {
            break;
        }
        
        for (int i = 0; i < NA; i++) {
            cin >> input;
            Card card;
            card.suit = input[0];
            card.rank = input[1];
            deckA.push_back(card);
        }
        
        cin >> NB;
        for (int i = 0; i < NB; i++) {
            cin >> input;
            Card card;
            card.suit = input[0];
            card.rank = input[1];
            deckB.push_back(card);
        }
        
        playGame(deckA, deckB);
        
        deckA.clear();
        deckB.clear();
    }
    
    return 0;
}