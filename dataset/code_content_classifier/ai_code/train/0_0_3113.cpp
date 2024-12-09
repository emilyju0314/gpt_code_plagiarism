#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double getProbability(int n, vector<int>& hand) {
    int jokerPos = -1;
    vector<int> counts(n + 1, 0);
    for(int card : hand) {
        if(card == 0) {
            jokerPos = counts.size();
        } else {
            counts[card]++;
        }
    }
    
    int totalPairs = 0;
    for(int i = 1; i <= n; i++) {
        totalPairs += counts[i] / 2;
    }
    
    if(jokerPos == -1 || (hand.size() == 1 && counts[jokerPos] == 1)) {
        return 0.0;
    }
    
    return 1.0 - totalPairs / (hand.size() - 1.0);
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> hands(3);
    for(int i = 0; i < 3; i++) {
        int size;
        cin >> size;
        hands[i].resize(size);
        for(int j = 0; j < size; j++) {
            cin >> hands[i][j];
        }
    }
    
    double prob = 0.0;
    for(int i = 0; i < 3; i++) {
        prob += getProbability(n, hands[i]);
    }
    
    cout << setprecision(10) << prob / 3.0 << endl;
    
    return 0;
}