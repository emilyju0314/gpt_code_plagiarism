#include <iostream>
#include <vector>

using namespace std;

vector<int> riffleShuffle(vector<int> deck, int c) {
    vector<int> deckA, deckB, deckC;
    
    int n = deck.size();
    
    for (int i = 0; i < n/2; i++) {
        deckA.push_back(deck[i]);
    }
    
    for (int i = n/2; i < n; i++) {
        deckB.push_back(deck[i]);
    }
    
    while (!deckA.empty() && !deckB.empty()) {
        for (int i = 0; i < c; i++) {
            if (!deckA.empty()) {
                deckC.push_back(deckA.back());
                deckA.pop_back();
            }
        }
        
        for (int i = 0; i < c; i++) {
            if (!deckB.empty()) {
                deckC.push_back(deckB.back());
                deckB.pop_back();
            }
        }
    }
    
    while (!deckA.empty()) {
        deckC.push_back(deckA.back());
        deckA.pop_back();
    }
    
    while (!deckB.empty()) {
        deckC.push_back(deckB.back());
        deckB.pop_back();
    }
    
    return deckC;
}

int main() {
    int n, r;
    
    while (cin >> n >> r) {
        vector<int> deck(n);
        
        for (int i = 0; i < n; i++) {
            deck[i] = i;
        }
        
        for (int i = 0; i < r; i++) {
            int c;
            cin >> c;
            deck = riffleShuffle(deck, c);
        }
        
        cout << deck.back() << endl;
    }
    
    return 0;
}