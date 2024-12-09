#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool canCompleteSolitaire(vector<string>& cards) {
    stack<pair<char, char>> piles;
    
    for (string card : cards) {
        char value = card[0];
        char suit = card[1];
        
        if (!piles.empty() && (piles.top().first == value || piles.top().second == suit)) {
            piles.pop();
        } else {
            piles.push(make_pair(value, suit));
        }
    }
    
    return piles.size() <= 1;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    
    if (canCompleteSolitaire(cards)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}