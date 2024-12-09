#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getRank(char c) {
    if (c == 'A') return 14;
    else if (c == 'K') return 13;
    else if (c == 'Q') return 12;
    else if (c == 'J') return 11;
    else if (c == 'T') return 10;
    else return c - '0';
}

bool isStraightFlush(vector<pair<char, char>>& cards) {
    sort(cards.begin(), cards.end(), [](const pair<char, char>& a, const pair<char, char>& b) {
        return getRank(a.second) < getRank(b.second);
    });

    if (cards[0].first == cards[1].first && cards[1].first == cards[2].first &&
        getRank(cards[0].second) + 1 == getRank(cards[1].second) &&
        getRank(cards[1].second) + 1 == getRank(cards[2].second)) {
        return true;
    }

    return false;
}

bool isStraight(vector<pair<char, char>>& cards) {
    sort(cards.begin(), cards.end(), [](const pair<char, char>& a, const pair<char, char>& b) {
        return getRank(a.second) < getRank(b.second);
    });

    if (getRank(cards[0].second) + 1 == getRank(cards[1].second) &&
        getRank(cards[1].second) + 1 == getRank(cards[2].second)) {
        return true;
    }

    return false;
}

// Add functions for other types of hands to check here

double calculateWinningProbability(vector<pair<char, char>>& myCards, vector<pair<char, char>>& opponentCards, vector<pair<char, char>>& flopCards) {
    // Combine the cards
    vector<pair<char, char>> remainingCards = {{'S', 'A'}, {'S', 'K'}, {'S', 'Q'}, {'S', 'J'}, {'S', 'T'},
                                               {'S', '9'}, {'S', '8'}, {'S', '7'}, {'S', '6'}, {'S', '5'},
                                               {'S', '4'}, {'S', '3'}, {'S', '2'}, {'H', 'A'}, {'H', 'K'},
                                               // Add all remaining cards here
                                               {'D', '2'}, {'D', '3'}, {'D', '4'}, {'D', '5'}, {'D', '6'},
                                               {'D', '7'}, {'D', '8'}, {'D', '9'}, {'D', 'T'}, {'D', 'J'},
                                               {'D', 'Q'}, {'D', 'K'}, {'D', 'A'}, {'C', '2'}, {'C', '3'},
                                               {'C', '4'}, {'C', '5'}, {'C', '6'}, {'C', '7'}, {'C', '8'},
                                               {'C', '9'}, {'C', 'T'}, {'C', 'J'}, {'C', 'Q'}, {'C', 'K'},
                                               {'C', 'A'}};

    double wins = 0, total = 0;

    for (int i = 0; i < remainingCards.size(); i++) {
        for (int j = i + 1; j < remainingCards.size(); j++) {
            vector<pair<char, char>> turnRiver = {remainingCards[i], remainingCards[j]};
            vector<pair<char, char>> myHand = {myCards[0], myCards[1], flopCards[0], flopCards[1], flopCards[2], turnRiver[0], turnRiver[1]};
            vector<pair<char, char>> opponentHand = {opponentCards[0], opponentCards[1], flopCards[0], flopCards[1], flopCards[2], turnRiver[0], turnRiver[1]};
            
            // Determine the ranks of the hands
            // Implement this based on the example comparison given
            
            // Check if myHand wins against opponentHand
        }
    }

    return wins / total;
}

int main() {
    while (true) {
        char myCard1Suit, myCard1Rank, myCard2Suit, myCard2Rank;
        cin >> myCard1Suit;
        if (myCard1Suit == '#') break;
        cin >> myCard1Rank;
        cin >> myCard2Suit;
        cin >> myCard2Rank;

        char opponentCard1Suit, opponentCard1Rank, opponentCard2Suit, opponentCard2Rank;
        cin >> opponentCard1Suit;
        cin >> opponentCard1Rank;
        cin >> opponentCard2Suit;
        cin >> opponentCard2Rank;

        char flop1Suit, flop1Rank, flop2Suit, flop2Rank, flop3Suit, flop3Rank;
        cin >> flop1Suit;
        cin >> flop1Rank;
        cin >> flop2Suit;
        cin >> flop2Rank;
        cin >> flop3Suit;
        cin >> flop3Rank;

        vector<pair<char, char>> myCards = {{myCard1Suit, myCard1Rank}, {myCard2Suit, myCard2Rank}};
        vector<pair<char, char>> opponentCards = {{opponentCard1Suit, opponentCard1Rank}, {opponentCard2Suit, opponentCard2Rank}};
        vector<pair<char, char>> flopCards = {{flop1Suit, flop1Rank}, {flop2Suit, flop2Rank}, {flop3Suit, flop3Rank}};

        double probability = calculateWinningProbability(myCards, opponentCards, flopCards);

        cout << probability << endl;
    }

    return 0;
}