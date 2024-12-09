#include <iostream>
#include <unordered_map>

using namespace std;

bool isTrump(char trump, char suit) {
    return suit == trump;
}

bool beatsCard(char trump, char rank1, char suit1, char rank2, char suit2) {
    if(isTrump(trump, suit1) && !isTrump(trump, suit2)) {
        return true;
    } else if(suit1 == suit2) {
        unordered_map<char, int> rankToInt{{'6', 0}, {'7', 1}, {'8', 2}, {'9', 3}, {'T', 4}, {'J', 5}, {'Q', 6}, {'K', 7}, {'A', 8}};
        return rankToInt[rank1] > rankToInt[rank2];
    }
    return false;
}

int main() {
    char trump;
    cin >> trump;

    string card1, card2;
    cin >> card1 >> card2;

    char rank1 = card1[0];
    char suit1 = card1[1];
    char rank2 = card2[0];
    char suit2 = card2[1];

    if(beatsCard(trump, rank1, suit1, rank2, suit2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}